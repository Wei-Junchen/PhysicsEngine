#include "system.hpp"

void System::update()
{
    //update the time
    time += dt;
    //iterate through all objects and update their motion
    for(auto& object :objects)
    {
        //update the position
        object->motion.position = object->motion.position + object->motion.velocity * dt;
        //update the velocityS
        object->motion.velocity = object->motion.velocity + object->motion.acceleration * dt;
        //update the rotation
        object->motion.rotation = object->motion.rotation + object->motion.angular_velocity * dt;
        //update the angular velocity
        object->motion.angular_velocity = object->motion.angular_velocity + object->motion.angular_acceleration * dt;
    }
}

void System::accCalc()
{
    for(auto& force : forces)
    {
        force->effect(); // Apply the effect of the force
    }
}