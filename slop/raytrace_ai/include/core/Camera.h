#pragma once
#include "../math/Vector3.h"

class RayCamera {
public:
    Vec3 position;
    Vec3 target;
    Vec3 up;
    float fov;
    
    RayCamera() : position(0, 0, 5), target(0, 0, 0), up(0, 1, 0), fov(60.0f) {}
    
    void move(const Vec3& delta) {
        position = position + delta;
        target = target + delta;
    }
    
    void rotate(float yaw, float pitch) {
        Vec3 forward = (target - position).normalized();
        
        // Yaw rotation (around Y axis)
        Vec3 right = forward.cross(up).normalized();
        Vec3 newForward = forward * std::cos(yaw) + right * std::sin(yaw);
        
        // Pitch rotation (around right axis)
        Vec3 newUp = newForward.cross(right).normalized();
        newForward = newForward * std::cos(pitch) + newUp * std::sin(pitch);
        
        target = position + newForward.normalized();
    }
};