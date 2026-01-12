#include "assets.h"
#include <cstdio>

#ifdef _WIN32
#include <windows.h>
#endif

std::string GetExecutableDirectory() {
    char path[512];
    #ifdef _WIN32
        GetModuleFileNameA(NULL, path, 512);
    #else
        uint32_t size = sizeof(path);
        _NSGetExecutablePath(path, &size);
    #endif
    
    std::string fullPath(path);
    size_t lastSlash = fullPath.find_last_of("\\/");
    if (lastSlash != std::string::npos) {
        return fullPath.substr(0, lastSlash);
    }
    return ".";
}

std::string GetAssetPath(const std::string& relativePath) {
    // First try relative to executable (for bundled builds)
    std::string exeDir = GetExecutableDirectory();
    std::string bundledPath = exeDir + "/" + relativePath;
    
    FILE* testFile = fopen(bundledPath.c_str(), "r");
    if (testFile) {
        fclose(testFile);
        return bundledPath;
    }
    
    // For macOS app bundles, try Resources directory
    #ifdef __APPLE__
    std::string resourcesPath = exeDir + "/../Resources/" + relativePath;
    testFile = fopen(resourcesPath.c_str(), "r");
    if (testFile) {
        fclose(testFile);
        return resourcesPath;
    }
    #endif
    
    // Fallback to relative path (for development)
    return relativePath;
}