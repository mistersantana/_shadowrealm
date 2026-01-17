#include "raylib.h"
#include "rlgl.h"
#include <cstdio>

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    
    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
    InitWindow(screenWidth, screenHeight, "Spinning Cube - First Person");
    SetTargetFPS(60);
    
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 10.0f, 10.0f, 10.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    
    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };
    float cubeSize = 2.0f;
    float rotationX = 0.0f;
    float rotationY = 0.0f;
    float rotationZ = 0.0f;
    bool autoRotate = true;
    
    DisableCursor();
    
    while (!WindowShouldClose()) {
        UpdateCamera(&camera, CAMERA_FIRST_PERSON);
        
        if (autoRotate) {
            rotationX += 0.5f;
            rotationY += 0.3f;
            rotationZ += 0.1f;
        } else {
            if (IsKeyDown(KEY_UP)) rotationX -= 1.0f;
            if (IsKeyDown(KEY_DOWN)) rotationX += 1.0f;
            if (IsKeyDown(KEY_LEFT)) rotationY -= 1.0f;
            if (IsKeyDown(KEY_RIGHT)) rotationY += 1.0f;
        }
        
        if (IsKeyPressed(KEY_SPACE)) autoRotate = !autoRotate;
        if (IsKeyPressed(KEY_R)) {
            rotationX = 0.0f;
            rotationY = 0.0f;
            rotationZ = 0.0f;
        }
        
        BeginDrawing();
            ClearBackground(BLACK);
            
            BeginMode3D(camera);
                rlPushMatrix();
                rlTranslatef(cubePosition.x, cubePosition.y, cubePosition.z);
                rlRotatef(rotationX, 1.0f, 0.0f, 0.0f);
                rlRotatef(rotationY, 0.0f, 1.0f, 0.0f);
                rlRotatef(rotationZ, 0.0f, 0.0f, 1.0f);
                DrawCubeWires((Vector3){0, 0, 0}, cubeSize, cubeSize, cubeSize, LIME);
                rlPopMatrix();
                
                DrawGrid(20, 1.0f);
            EndMode3D();
            
            DrawFPS(10, 10);
            DrawText("WASD/Arrows: Move camera | Mouse: Look", 10, 40, 10, RAYWHITE);
            DrawText("Arrow Keys: Rotate cube (manual mode) | Space: Toggle auto-rotate", 10, 55, 10, RAYWHITE);
            DrawText("R: Reset rotation | ESC: Exit", 10, 70, 10, RAYWHITE);
            
            const char* modeText = autoRotate ? "Auto-rotate ON" : "Manual control ON";
            DrawText(modeText, 10, 85, 10, autoRotate ? GREEN : YELLOW);
            
            char rotationInfo[64];
            snprintf(rotationInfo, sizeof(rotationInfo), "Rotation: X=%.1f Y=%.1f Z=%.1f", rotationX, rotationY, rotationZ);
            DrawText(rotationInfo, 10, 100, 10, GRAY);
            
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}
