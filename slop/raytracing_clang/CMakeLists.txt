cmake_minimum_required(VERSION 4.0)

project(raytracing
  LANGUAGES C
)

set(CMAKE_C_STANDARD)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(raytracing
  src/main.c
)

find_package(SDL3 REQUIRED)
target_link_libraries(raytracing PRIVATE SDL3::SDL3)
