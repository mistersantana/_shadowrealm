cmake_minimum_required (VERSION 4.0)

project(Cube
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Cube
  src/cube.cpp
)

find_package(raylib REQUIRED)
target_link_libraries(Cube PRIVATE raylib)
