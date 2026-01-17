cmake_minimum_required(VERSION 3.10)
project(RaytraceAI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set raylib path
set(RAYLIB_DIR /opt/homebrew/opt/raylib)
set(RAYLIB_INCLUDE_DIR ${RAYLIB_DIR}/include)
set(RAYLIB_LIBRARY_DIR ${RAYLIB_DIR}/lib)

# Include raylib headers
include_directories(${RAYLIB_INCLUDE_DIR})
link_directories(${RAYLIB_LIBRARY_DIR})

# Create executable
add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/math/Vector3.cpp
    src/math/Ray.cpp
    src/geometry/Sphere.cpp
    src/core/Camera.cpp
    src/core/Raytracer.cpp
)

# Link raylib
target_link_libraries(${PROJECT_NAME} PRIVATE 
    ${RAYLIB_LIBRARY_DIR}/libraylib.a
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreAudio"
    "-framework CoreVideo"
)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Set output directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)