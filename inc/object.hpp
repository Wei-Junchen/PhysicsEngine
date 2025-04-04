#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__

#include "math.hpp"

using Position = engine::vector3d;
using Rotation = engine::vector3d; // Assuming rotation is represented as a vector (e.g., Euler angles or axis-angle representation)
using Velocity = engine::vector3d;
using Acceleration = engine::vector3d;
using AngularVelocity = engine::vector3d; // Assuming angular velocity is also a vector
using AngularAcceleration = engine::vector3d; // Assuming angular acceleration is also a vector

struct Properties
{
    double mass {};
    double inertia {};
};

struct Motion
{
    Position position;
    Rotation rotation;
    Velocity velocity;
    Acceleration acceleration;
    AngularVelocity angular_velocity;
    AngularAcceleration angular_acceleration;
};

class Object
{
private:
    Properties properties;
public:
    Motion motion;
    void setMass(double m) { properties.mass = m; }
    double getMass() const { return properties.mass; }
    void setInertia(double i) { properties.inertia = i; }
    double getInertia() const { return properties.inertia; }
};


#endif