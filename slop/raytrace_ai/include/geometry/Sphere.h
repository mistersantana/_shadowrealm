#pragma once
#include "../math/Vector3.h"
#include "../math/Color.h"
#include "../math/Ray.h"
#include "../math/HitResult.h"

class Sphere {
public:
    Vec3 center;
    float radius;
    Vec3Color color;
    
    Sphere() : radius(1.0f) {}
    Sphere(const Vec3& center, float radius, const Vec3Color& color)
        : center(center), radius(radius), color(color) {}
    
    HitResult intersect(const Ray3& ray) const {
        Vec3 oc = ray.origin - center;
        float a = ray.direction.dot(ray.direction);
        float b = 2.0f * oc.dot(ray.direction);
        float c = oc.dot(oc) - radius * radius;
        
        float discriminant = b * b - 4 * a * c;
        if (discriminant < 0) {
            return HitResult();
        }
        
        float t = (-b - std::sqrt(discriminant)) / (2.0f * a);
        if (t > 0.001f) {
            Vec3 point = ray.pointAt(t);
            Vec3 normal = (point - center).normalized();
            return HitResult(t, point, normal);
        }
        
        return HitResult();
    }
};