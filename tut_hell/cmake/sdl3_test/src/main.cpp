#include <SDL3/SDL.h>
#include <cstdio>

int main() {
    if (!SDL_Init(SDL_INIT_VIDEO)) { // SDL3 returns bool
        std::printf("SDL_Init failed: %s\n", SDL_GetError());
        return 1;
    }

    const int v = SDL_GetVersion(); // returns int in SDL3
    std::printf("SDL version num: %d\n", v);

    // If you want human-friendly version parts, SDL provides macros in SDL_version.h.
    // (They’re available via SDL.h includes.)
    std::printf("SDL version: %d.%d.%d\n",
                SDL_VERSIONNUM_MAJOR(v),
                SDL_VERSIONNUM_MINOR(v),
                SDL_VERSIONNUM_MICRO(v));

    SDL_Quit();
    return 0;
}
