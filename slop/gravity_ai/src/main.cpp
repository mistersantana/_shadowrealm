#include <raylib.h>
#include <raymath.h>
#include <rlgl.h>
#include <cmath>

struct PhysicsSphere {
    Vector3 position;
    Vector3 velocity;
    float radius;
    float mass;
    
    PhysicsSphere(float r = 1.0f) : radius(r), mass(1.0f) {
        position = {0.0f, 10.0f, 0.0f};
        velocity = {0.0f, 0.0f, 0.0f};
    }
    
    void Reset() {
        position = {0.0f, 10.0f, 0.0f};
        velocity = {0.0f, 0.0f, 0.0f};
    }
    
    void Update(float deltaTime, float gravity, float damping) {
        // Apply gravity
        velocity.y -= gravity * deltaTime;
        
        // Update position
        position.x += velocity.x * deltaTime;
        position.y += velocity.y * deltaTime;
        position.z += velocity.z * deltaTime;
        
        // Check collision with ground plane (y = 0)
        if (position.y - radius <= 0.0f) {
            position.y = radius; // Place sphere exactly on ground
            
            // Apply bounce with damping
            velocity.y = -velocity.y * damping;
            
            // Stop tiny bounces
            if (fabsf(velocity.y) < 0.1f) {
                velocity.y = 0.0f;
            }
        }
    }
};

int main() {
    const int screenWidth = 1200;
    const int screenHeight = 800;
    
    InitWindow(screenWidth, screenHeight, "Gravity Physics Simulation");
    SetTargetFPS(60);
    
    // Initialize physics sphere
    PhysicsSphere sphere(1.0f);
    
    // Physics parameters
    float gravity = 9.81f;
    float damping = 0.8f;
    bool isPaused = false;
    
    // Camera setup
    Camera3D camera = { 0 };
    camera.position = { 10.0f, 8.0f, 10.0f };
    camera.target = { 0.0f, 2.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    
    // UI variables
    float gravitySlider = gravity;
    float radiusSlider = sphere.radius;
    float dampingSlider = damping;
    
    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        
        // Handle pause toggle
        if (IsKeyPressed(KEY_SPACE)) {
            isPaused = !isPaused;
        }
        
        // Handle reset
        if (IsKeyPressed(KEY_R)) {
            sphere.Reset();
        }
        
        // Update physics
        if (!isPaused) {
            sphere.Update(deltaTime, gravitySlider, dampingSlider);
        }
        
        // Update camera
        UpdateCamera(&camera, CAMERA_ORBITAL);
        
        // Update sphere radius if changed
        sphere.radius = radiusSlider;
        
        // Draw everything
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        // 3D Scene
        BeginMode3D(camera);
        
        // Draw ground plane
        DrawGrid(20, 1.0f);
        
        // Draw a plane for better ground visualization  
        DrawPlane({0.0f, 0.0f, 0.0f}, {20.0f, 20.0f}, LIGHTGRAY);
        
        // Draw wireframe sphere
        DrawSphereWires(sphere.position, sphere.radius, 16, 16, MAROON);
        
        // Draw coordinate axes for reference
        DrawLine3D({0, 0, 0}, {5, 0, 0}, RED);     // X axis
        DrawLine3D({0, 0, 0}, {0, 5, 0}, GREEN);   // Y axis  
        DrawLine3D({0, 0, 0}, {0, 0, 5}, BLUE);    // Z axis
        
        EndMode3D();
        
        // UI Controls
        DrawRectangle(10, 10, 250, 200, Fade(SKYBLUE, 0.5f));
        DrawRectangleLines(10, 10, 250, 200, BLUE);
        
        DrawText("GRAVITY SIMULATION", 20, 20, 20, BLACK);
        
        // Gravity control
        DrawText("Gravity:", 20, 50, 10, BLACK);
        DrawText(TextFormat("%.1f m/s²", gravitySlider), 80, 50, 10, BLACK);
        DrawText("(G/H +/-)", 150, 50, 8, GRAY);
        if (IsKeyPressed(KEY_G)) gravitySlider = fminf(20.0f, gravitySlider + 0.5f);
        if (IsKeyPressed(KEY_H)) gravitySlider = fmaxf(0.1f, gravitySlider - 0.5f);
        
        // Radius control  
        DrawText("Radius:", 20, 70, 10, BLACK);
        DrawText(TextFormat("%.1f", radiusSlider), 80, 70, 10, BLACK);
        DrawText("(+/-)", 150, 70, 8, GRAY);
        if (IsKeyPressed(KEY_EQUAL) || IsKeyPressed(KEY_KP_ADD)) radiusSlider = fminf(3.0f, radiusSlider + 0.1f);
        if (IsKeyPressed(KEY_MINUS)) radiusSlider = fmaxf(0.5f, radiusSlider - 0.1f);
        
        // Damping control
        DrawText("Damping:", 20, 90, 10, BLACK);
        DrawText(TextFormat("%.2f", dampingSlider), 80, 90, 10, BLACK);
        DrawText("(D/F +/-)", 150, 90, 8, GRAY);
        if (IsKeyPressed(KEY_D)) dampingSlider = fminf(1.0f, dampingSlider + 0.1f);
        if (IsKeyPressed(KEY_F)) dampingSlider = fmaxf(0.0f, dampingSlider - 0.1f);
        
        // Status
        DrawText(isPaused ? "PAUSED" : "RUNNING", 20, 110, 10, isPaused ? RED : GREEN);
        
        // Controls help
        DrawText("Controls:", 20, 130, 10, BLACK);
        DrawText("SPACE - Pause/Resume", 30, 145, 9, DARKGRAY);
        DrawText("R - Reset sphere", 30, 160, 9, DARKGRAY);
        DrawText("Mouse - Camera", 30, 175, 9, DARKGRAY);
        
        // Physics info
        DrawRectangle(screenWidth - 210, 10, 200, 120, Fade(LIGHTGRAY, 0.5f));
        DrawRectangleLines(screenWidth - 210, 10, 200, 120, GRAY);
        DrawText("PHYSICS INFO", screenWidth - 200, 20, 15, BLACK);
        DrawText(TextFormat("Pos Y: %.2f", sphere.position.y), screenWidth - 200, 40, 10, BLACK);
        DrawText(TextFormat("Vel Y: %.2f", sphere.velocity.y), screenWidth - 200, 55, 10, BLACK);
        DrawText(TextFormat("Height: %.2f", sphere.position.y - sphere.radius), screenWidth - 200, 70, 10, BLACK);
        DrawText(TextFormat("FPS: %d", GetFPS()), screenWidth - 200, 85, 10, BLACK);
        
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}