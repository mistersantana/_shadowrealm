#pragma once
#include <string>

#ifdef __APPLE__
#include <mach-o/dyld.h>
#endif

// Get the directory where the executable is located
std::string GetExecutableDirectory();

// Get asset path that works for both development and bundled builds
std::string GetAssetPath(const std::string& relativePath);