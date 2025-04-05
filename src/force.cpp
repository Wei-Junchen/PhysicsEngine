#include "force.hpp"
#include <iostream>

void Gravity::effect()
{
    engine::vector3d direction = object_1->motion.position - object_2->motion.position;
    double force = G * (object_1->getMass() * object_2->getMass()) / (direction.dot(direction) + 1e-10); // Adding a small value to avoid division by zero
    object_1->motion.acceleration += -(force / object_1->getMass() ) * direction;
    object_2->motion.acceleration += (force / object_2->getMass()) * direction;
    // std::cout<<object_1<<object_1->motion.acceleration<<std::endl;
    // std::cout<<object_2<<object_2->motion.acceleration<<std::endl;
}  