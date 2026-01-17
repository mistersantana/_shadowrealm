#include <raylib.h>
#include "core/Camera.h"
#include "core/Raytracer.h"
#include "math/Vector3.h"
#include "math/Ray.h"
#include <iostream>

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    
    InitWindow(screenWidth, screenHeight, "Raytracing Demo");
    SetTargetFPS(60);
    
    // Create render texture
    RenderTexture2D renderTexture = LoadRenderTexture(screenWidth, screenHeight);
    
    RayCamera camera;
    Raytracer raytracer;
    
    // Camera controls
    float cameraSpeed = 0.1f;
    
    while (!WindowShouldClose()) {
        // Update camera
        if (IsKeyDown(KEY_W)) camera.move(Vec3(0, 0, -cameraSpeed));
        if (IsKeyDown(KEY_S)) camera.move(Vec3(0, 0, cameraSpeed));
        if (IsKeyDown(KEY_A)) camera.move(Vec3(-cameraSpeed, 0, 0));
        if (IsKeyDown(KEY_D)) camera.move(Vec3(cameraSpeed, 0, 0));
        if (IsKeyDown(KEY_Q)) camera.move(Vec3(0, cameraSpeed, 0));
        if (IsKeyDown(KEY_E)) camera.move(Vec3(0, -cameraSpeed, 0));
        
        // Mouse rotation
        if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
            float mouseDeltaX = GetMouseDelta().x * 0.01f;
            float mouseDeltaY = GetMouseDelta().y * 0.01f;
            camera.rotate(mouseDeltaX, mouseDeltaY);
        }
        
        // Raytrace to texture
        BeginTextureMode(renderTexture);
        {
            ClearBackground(BLACK);
            
            for (int y = 0; y < screenHeight; y++) {
                for (int x = 0; x < screenWidth; x++) {
                    // Calculate ray direction
                    float u = (2.0f * x) / screenWidth - 1.0f;
                    float v = 1.0f - (2.0f * y) / screenHeight;
                    
                    Vec3 forward = (camera.target - camera.position).normalized();
                    Vec3 right = forward.cross(camera.up).normalized();
                    Vec3 up = right.cross(forward).normalized();
                    
                    float aspectRatio = (float)screenWidth / screenHeight;
                    float fovRad = camera.fov * 3.14159f / 180.0f;
                    float h = std::tan(fovRad / 2.0f);
                    
                    Vec3 rayDir = (forward + right * u * h * aspectRatio + up * v * h).normalized();
                    Ray3 ray(camera.position, rayDir);
                    
                    // Trace ray
                    Vec3Color color = raytracer.traceRay(ray);
                    
                    // Convert to raylib color format (0-255)
                    unsigned char r = (unsigned char)(color.r * 255);
                    unsigned char g = (unsigned char)(color.g * 255);
                    unsigned char b = (unsigned char)(color.b * 255);
                    
                    DrawPixel(x, y, {r, g, b, 255});
                }
            }
        }
        EndTextureMode();
        
        // Draw to screen
        BeginDrawing();
        {
            ClearBackground(BLACK);
            DrawTextureRec(renderTexture.texture, 
                          {0, 0, (float)screenWidth, -(float)screenHeight}, 
                          {0, 0}, WHITE);
            
            // Draw instructions
            DrawText("WASD: Move camera", 10, 10, 20, RAYWHITE);
            DrawText("Q/E: Up/Down", 10, 35, 20, RAYWHITE);
            DrawText("Right Mouse: Rotate", 10, 60, 20, RAYWHITE);
            DrawFPS(screenWidth - 100, 10);
        }
        EndDrawing();
    }
    
    UnloadRenderTexture(renderTexture);
    CloseWindow();
    
    return 0;
}