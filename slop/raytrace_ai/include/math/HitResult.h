#pragma once
#include "Vector3.h"
#include "Ray.h"

struct HitResult {
    bool hit;
    float distance;
    Vec3 point;
    Vec3 normal;
    
    HitResult() : hit(false), distance(0) {}
    HitResult(float distance, const Vec3& point, const Vec3& normal)
        : hit(true), distance(distance), point(point), normal(normal) {}
};