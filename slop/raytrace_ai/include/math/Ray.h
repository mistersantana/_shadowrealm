#pragma once
#include "Vector3.h"

struct Ray3 {
    Vec3 origin;
    Vec3 direction;
    
    Ray3() {}
    Ray3(const Vec3& origin, const Vec3& direction) 
        : origin(origin), direction(direction.normalized()) {}
    
    Vec3 pointAt(float t) const {
        return origin + direction * t;
    }
};