#pragma once
#include "../geometry/Sphere.h"
#include "../core/Camera.h"
#include "../math/Vector3.h"
#include "../math/Color.h"
#include "../math/Ray.h"
#include "../math/HitResult.h"
#include <vector>

class Raytracer {
private:
    std::vector<Sphere> spheres;
    
public:
    Raytracer() {
        // Initialize scene with some spheres
        spheres.push_back(Sphere(Vec3(0, 0, 0), 1.0f, Vec3Color(1.0f, 0.2f, 0.2f)));
        spheres.push_back(Sphere(Vec3(2, 0, -1), 0.8f, Vec3Color(0.2f, 1.0f, 0.2f)));
        spheres.push_back(Sphere(Vec3(-2, 0, -1), 0.8f, Vec3Color(0.2f, 0.2f, 1.0f)));
        spheres.push_back(Sphere(Vec3(0, -100.5f, 0), 100.0f, Vec3Color(0.5f, 0.5f, 0.5f)));
    }
    
    HitResult findClosestHit(const Ray3& ray) {
        HitResult closestHit;
        for (const auto& sphere : spheres) {
            HitResult hit = sphere.intersect(ray);
            if (hit.hit && (!closestHit.hit || hit.distance < closestHit.distance)) {
                closestHit = hit;
            }
        }
        return closestHit;
    }
    
    Vec3Color traceRay(const Ray3& ray, int depth = 0) {
        if (depth >= 3) return Vec3Color(0.1f, 0.1f, 0.1f); // Background color
        
        HitResult hit = findClosestHit(ray);
        if (!hit.hit) {
            // Sky gradient
            float t = 0.5f * (ray.direction.y + 1.0f);
            return Vec3Color(1.0f, 1.0f, 1.0f) * (1.0f - t) + Vec3Color(0.5f, 0.7f, 1.0f) * t;
        }
        
        // Find the sphere that was hit
        Vec3Color sphereColor;
        for (const auto& sphere : spheres) {
            HitResult testHit = sphere.intersect(ray);
            if (testHit.hit && std::abs(testHit.distance - hit.distance) < 0.001f) {
                sphereColor = sphere.color;
                break;
            }
        }
        
        // Simple lighting
        Vec3 lightDir = Vec3(1, 1, -1).normalized();
        float diffuse = std::max(0.0f, hit.normal.dot(lightDir));
        
        // Shadow
        Ray3 shadowRay(hit.point + hit.normal * 0.001f, lightDir);
        HitResult shadowHit = findClosestHit(shadowRay);
        if (shadowHit.hit) {
            diffuse = 0.1f; // Ambient light only
        }
        
        return sphereColor * diffuse + sphereColor * 0.1f; // Add ambient
    }
};