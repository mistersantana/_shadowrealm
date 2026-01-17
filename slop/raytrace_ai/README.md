# Raytracing Demo

A simple real-time raytracing demo built with C++ and raylib.

## Features

- Real-time raytracing with sphere primitives
- Interactive camera controls (WASD movement + mouse rotation)
- Basic lighting and shadows
- Gradient sky background
- Colored spheres with different materials

## Controls

- **WASD**: Move camera horizontally and forward/backward
- **Q/E**: Move camera up/down
- **Right Mouse Button + Drag**: Rotate camera view
- **ESC**: Exit application

## Build Instructions

### Prerequisites

- CMake 3.10 or higher
- C++17 compatible compiler
- raylib library (install via `brew install raylib` on macOS)

### Building

```bash
mkdir build
cd build
cmake ..
make
```

### Running

```bash
./bin/RaytraceAI
```

## Project Structure

```
├── CMakeLists.txt          # Build configuration
├── README.md              # This file
├── include/               # Header files
│   ├── core/             # Core raytracing logic
│   │   ├── Camera.h      # Camera class
│   │   └── Raytracer.h  # Main raytracer
│   ├── geometry/         # Geometric primitives
│   │   └── Sphere.h      # Sphere implementation
│   └── math/             # Math utilities
│       ├── Color.h       # Color structure
│       ├── Ray.h         # Ray structure
│       ├── Vector3.h     # 3D vector math
│       └── HitResult.h   # Ray-sphere intersection result
└── src/                   # Source files
    ├── core/             # Core implementations
    ├── geometry/         # Geometry implementations
    ├── math/             # Math implementations
    └── main.cpp          # Main application entry
```

## How It Works

1. **Ray Generation**: For each pixel, a ray is cast from the camera through the pixel
2. **Intersection Testing**: Each ray is tested against all spheres in the scene
3. **Lighting Calculation**: Basic diffuse lighting with shadow rays
4. **Color Output**: Final color is written to a texture and displayed

## Performance Considerations

- Current implementation runs pixel-by-pixel for maximum clarity
- Performance is limited by CPU raytracing speed
- Future optimizations could include:
  - Multi-threading
  - Spatial partitioning (BVH)
  - SIMD instructions
  - GPU acceleration via compute shaders

## Future Enhancements

- [ ] Add more primitive shapes (planes, boxes)
- [ ] Implement reflections and refractions
- [ ] Add texture mapping
- [ ] Multi-sampling for anti-aliasing
- [ ] Performance optimizations