cmake_minimum_required(VERSION 3.15)

project(test
  VERSION 99
  LANGUAGES CXX
)

add_executable(Test
  raytest.cpp
)

find_package(raylib REQUIRED)
target_link_libraries(Test PRIVATE raylib)
