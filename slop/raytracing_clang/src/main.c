#include <SDL3/SDL.h>
#include <math.h>
#include <stdint.h>

#define START_WIDTH  1280
#define START_HEIGHT 720
#define RAYS_NUMBER  500

// ARGB (A in highest byte)
#define COLOR_WHITE_ARGB 0xffffffffu
#define COLOR_BLACK_ARGB 0x00000000u
#define COLOR_GRAY_ARGB  0xefefefefu

struct Circle {
    double x, y, radius;
};

struct Ray {
    double x_start, y_start, angle;
};

/* Convert ARGB (0xAARRGGBB) into the surface's native pixel format */
static Uint32 MapARGB(SDL_Surface *surface, Uint32 argb) {
    Uint8 a = (argb >> 24) & 0xFF;
    Uint8 r = (argb >> 16) & 0xFF;
    Uint8 g = (argb >> 8)  & 0xFF;
    Uint8 b = (argb)       & 0xFF;
    const SDL_PixelFormatDetails *details = SDL_GetPixelFormatDetails(surface->format);
    const SDL_Palette *palette = SDL_GetSurfacePalette(surface);
    if (!details) return 0;
    return SDL_MapRGBA(details, palette, r, g, b, a);
}

/* Fast pixel write (assumes surface is writable). */
static inline void PutPixel(SDL_Surface *surface, int x, int y, Uint32 pixel) {
    if ((unsigned)x >= (unsigned)surface->w || (unsigned)y >= (unsigned)surface->h) return;

    // Most window surfaces will be 32bpp, but we handle any BytesPerPixel.
    const SDL_PixelFormatDetails *details = SDL_GetPixelFormatDetails(surface->format);
    if (!details) return;
    const int bpp = details->bytes_per_pixel;
    Uint8 *row = (Uint8 *)surface->pixels + y * surface->pitch;
    Uint8 *dst = row + x * bpp;

    switch (bpp) {
        case 4:
            *(Uint32 *)dst = pixel;
            break;
        case 3:
            // Write least-significant 3 bytes
            dst[0] = (Uint8)(pixel & 0xFF);
            dst[1] = (Uint8)((pixel >> 8) & 0xFF);
            dst[2] = (Uint8)((pixel >> 16) & 0xFF);
            break;
        case 2:
            *(Uint16 *)dst = (Uint16)pixel;
            break;
        case 1:
            *dst = (Uint8)pixel;
            break;
        default:
            // Unusual format, fallback to nothing
            break;
    }
}

static void FillCircle(SDL_Surface *surface, struct Circle circle, Uint32 color_pixel) {
    const int cx = (int)lround(circle.x);
    const int cy = (int)lround(circle.y);
    const int r  = (int)lround(circle.radius);

    const int r2 = r * r;

    const int x0 = cx - r;
    const int x1 = cx + r;
    const int y0 = cy - r;
    const int y1 = cy + r;

    for (int y = y0; y <= y1; y++) {
        const int dy = y - cy;
        const int dy2 = dy * dy;
        for (int x = x0; x <= x1; x++) {
            const int dx = x - cx;
            const int d2 = dx * dx + dy2;
            if (d2 <= r2) {
                PutPixel(surface, x, y, color_pixel);
            }
        }
    }
}

static void generate_rays(struct Circle circle, struct Ray rays[RAYS_NUMBER]) {
    for (int i = 0; i < RAYS_NUMBER; i++) {
        double angle = ((double)i / (double)RAYS_NUMBER) * 2.0 * M_PI;
        rays[i].x_start = circle.x;
        rays[i].y_start = circle.y;
        rays[i].angle   = angle;
    }
}

static void FillRays(SDL_Surface *surface,
                     const struct Ray rays[RAYS_NUMBER],
                     Uint32 color_pixel,
                     struct Circle object)
{
    const double ox = object.x;
    const double oy = object.y;
    const double r2 = object.radius * object.radius;

    const int w = surface->w;
    const int h = surface->h;

    for (int i = 0; i < RAYS_NUMBER; i++) {
        double x = rays[i].x_start;
        double y = rays[i].y_start;

        const double ca = cos(rays[i].angle);
        const double sa = sin(rays[i].angle);

        // 1px steps like your original (keeps the same look)
        for (;;) {
            x += ca;
            y += sa;

            const int xi = (int)lround(x);
            const int yi = (int)lround(y);

            // stop at screen edge
            if (xi < 0 || xi >= w || yi < 0 || yi >= h) break;

            PutPixel(surface, xi, yi, color_pixel);

            // stop when hitting the "shadow" circle
            const double dx = x - ox;
            const double dy = y - oy;
            if (dx * dx + dy * dy <= r2) break;
        }
    }
}

int main(int argc, char **argv) {
    (void)argc; (void)argv;

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Rays!", START_WIDTH, START_HEIGHT, SDL_WINDOW_RESIZABLE);
    if (!window) {
        SDL_Log("SDL_CreateWindow failed: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Surface *surface = SDL_GetWindowSurface(window);
    if (!surface) {
        SDL_Log("SDL_GetWindowSurface failed: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Map colors once (important if the surface isn't ARGB8888)
    Uint32 COLOR_WHITE = MapARGB(surface, COLOR_WHITE_ARGB);
    Uint32 COLOR_BLACK = MapARGB(surface, COLOR_BLACK_ARGB);
    Uint32 COLOR_GRAY  = MapARGB(surface, COLOR_GRAY_ARGB);

    SDL_Rect erase_rect = {0, 0, surface->w, surface->h};

    struct Circle circle        = {200, 200, 80};
    struct Circle shadow_circle = {500, 300, 140};

    struct Ray rays[RAYS_NUMBER];
    generate_rays(circle, rays);

    SDL_Event event;
    int sim_running = 1;

    while (sim_running) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT:
                    sim_running = 0;
                    break;

                case SDL_EVENT_WINDOW_RESIZED:
                case SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED:
                    // Window surface can change on resize, re-fetch and remap colors
                    surface = SDL_GetWindowSurface(window);
                    if (surface) {
                        erase_rect.w = surface->w;
                        erase_rect.h = surface->h;
                        COLOR_WHITE = MapARGB(surface, COLOR_WHITE_ARGB);
                        COLOR_BLACK = MapARGB(surface, COLOR_BLACK_ARGB);
                        COLOR_GRAY  = MapARGB(surface, COLOR_GRAY_ARGB);
                    } else {
                        SDL_Log("SDL_GetWindowSurface failed after resize: %s", SDL_GetError());
                    }
                    break;

                case SDL_EVENT_MOUSE_MOTION:
                    // Drag to move emitter (matches your "motion.state != 0" intent)
                    if (event.motion.state != 0) {
                        circle.x = event.motion.x;
                        circle.y = event.motion.y;
                        generate_rays(circle, rays);
                    }
                    break;
            }
        }

        if (!surface) {
            surface = SDL_GetWindowSurface(window);
            if (!surface) {
                SDL_Log("SDL_GetWindowSurface failed: %s", SDL_GetError());
                SDL_Delay(16);
                continue;
            }
            erase_rect.w = surface->w;
            erase_rect.h = surface->h;
            COLOR_WHITE = MapARGB(surface, COLOR_WHITE_ARGB);
            COLOR_BLACK = MapARGB(surface, COLOR_BLACK_ARGB);
            COLOR_GRAY  = MapARGB(surface, COLOR_GRAY_ARGB);
        }

        SDL_FillSurfaceRect(surface, &erase_rect, COLOR_BLACK);

        // Lock surface if needed (usually fine either way, but safe for direct writes)
        if (SDL_MUSTLOCK(surface) && !SDL_LockSurface(surface)) {
            SDL_Log("SDL_LockSurface failed: %s", SDL_GetError());
            SDL_Delay(16);
            continue;
        }

        FillCircle(surface, circle, COLOR_WHITE);
        FillCircle(surface, shadow_circle, COLOR_WHITE);
        FillRays(surface, rays, COLOR_GRAY, shadow_circle);

        if (SDL_MUSTLOCK(surface)) SDL_UnlockSurface(surface);

        SDL_UpdateWindowSurface(window);
        SDL_Delay(16);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
