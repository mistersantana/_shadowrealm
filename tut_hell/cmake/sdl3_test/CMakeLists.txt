cmake_minimum_required(VERSION 3.13)
project(sdl3_test)

add_executable(Main src/main.cpp)

find_package(SDL3 REQUIRED CONFIG)
target_link_libraries(Main PRIVATE SDL3::SDL3)
