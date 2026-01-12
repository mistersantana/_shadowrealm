cmake_minimum_required(VERSION 3.16)
project(sfml_test LANGUAGES CXX)

add_executable(Main src/main.cpp)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

target_link_libraries (Main PRIVATE
  SFML::Graphics
  SFML::Window
  SFML::System
)
