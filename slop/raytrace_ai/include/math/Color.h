#pragma once
#include "../math/Vector3.h"

struct Vec3Color {
    float r, g, b;
    
    Vec3Color() : r(0), g(0), b(0) {}
    Vec3Color(float r, float g, float b) : r(r), g(g), b(b) {}
    
    Vec3Color operator+(const Vec3Color& other) const {
        return Vec3Color(r + other.r, g + other.g, b + other.b);
    }
    
    Vec3Color operator*(float scalar) const {
        return Vec3Color(r * scalar, g * scalar, b * scalar);
    }
    
    Vec3Color operator*(const Vec3Color& other) const {
        return Vec3Color(r * other.r, g * other.g, b * other.b);
    }
};