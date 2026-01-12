#include <iostream>
#include <raylib.h>

const int screenWidth = 1280;
const int screenHeight = 720;

int main() {
  std::cout << "Hello Raylib!" << std::endl;

  InitWindow(screenWidth, screenHeight, "WEEEEEE!!");

  while (!WindowShouldClose()) {
    BeginDrawing();
      ClearBackground(BLACK);
      DrawCircle(screenWidth/2, screenHeight/2, 100, RAYWHITE);
    EndDrawing();
  }

  CloseWindow();
}
