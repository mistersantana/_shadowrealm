#include "raylib.h"

int main() {
  InitWindow(800, 450, "Raylib 3D Test");
  SetTargetFPS(90);

  Camera3D cam{};
  cam.position = { 4.0f, 2.0f, 4.0f };
  cam.target   = { 0.0f, 1.0f, 0.0f };
  cam.up       = { 0.0f, 1.0f, 0.0f };
  cam.fovy     = 90.0f;
  cam.projection = CAMERA_PERSPECTIVE;

  while (!WindowShouldClose()) {
    UpdateCamera(&cam, CAMERA_ORBITAL);

    BeginDrawing();
    ClearBackground(RAYWHITE);

    BeginMode3D(cam);
    DrawGrid(20, 1.0f);
    DrawCube({0, 1, 0}, 1, 1, 1, RED);
    DrawCubeWires({0, 1, 0}, 1, 1, 1, MAROON);
    EndMode3D();

    DrawText("Whee 3D Cube!", 10, 10, 20, DARKGRAY);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
