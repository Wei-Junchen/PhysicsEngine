#include "force.hpp"
#include <iostream>

void Gravity::effect()
{
    engine::vector3d direction = object_1->motion.position - object_2->motion.position;
    // std::cout<<"Object 1 Position: "<<object_1->motion.position._1<<","<<object_1->motion.position._2<<","<<object_1->motion.position._3<<std::endl;
    // std::cout<<"Object 2 Position: "<<object_2->motion.position._1<<","<<object_2->motion.position._2<<","<<object_2->motion.position._3<<std::endl;
    // std::cout<<"Direction: "<<direction._1<<","<<direction._2<<","<<direction._3<<std::endl;
    double force = G * (object_1->getMass() * object_2->getMass()) / (direction.dot(direction) + 1e-10); // Adding a small value to avoid division by zero
    object_1->motion.acceleration += (force / object_1->getMass() ) * direction;
    object_2->motion.acceleration += (-(force / object_2->getMass())) * direction;
    // std::cout<<"Force Scalar: "<<force<<std::endl;
}