# Tetris Raylib - Cross-Platform Builds

This is a classic Tetris clone built with C++ and Raylib.

## 🎮 How to Run

### Windows
1. Download `tetris-windows-x64.zip`
2. Extract the zip file
3. Double-click `tetris.exe`

### macOS
1. Download `tetris-macos-universal.zip`
2. Extract the zip file
3. Double-click `Tetris.app`
4. If you get a security warning: Right-click → Open → Open Anyway

## 🎮 Controls

- **Arrow Keys**: Move pieces left/right/down
- **Up Arrow**: Rotate piece
- **Any key after game over**: Restart

## 🛠️ Build Instructions

### Prerequisites
- CMake 3.15+
- C++17 compiler
- Raylib 5.0+

### Build
```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make
```

## 📦 Distribution

Automatically built cross-platform executables are available via GitHub Actions when you push to main or create a release tag.

- **Static linking**: No external dependencies
- **Asset bundling**: Font and sound files included
- **Universal macOS**: Works on Intel and Apple Silicon

Made with ❤️ using [Raylib](https://www.raylib.com/)