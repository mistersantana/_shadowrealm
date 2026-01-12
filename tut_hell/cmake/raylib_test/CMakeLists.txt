cmake_minimum_required(VERSION 3.13)
project(raylib_test LANGUAGES CXX)

add_executable(Main src/main.cpp)

find_package(raylib REQUIRED)
target_link_libraries(Main PRIVATE raylib)
