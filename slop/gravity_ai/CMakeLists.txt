cmake_minimum_required(VERSION 4.0)

project(gravity
  VERSION 0.1
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20) #
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(gravity
  src/main.cpp
)

find_package(raylib REQUIRED)
target_link_libraries(gravity PRIVATE raylib)
