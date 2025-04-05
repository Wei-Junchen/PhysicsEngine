#include "system.hpp"
#include <utility> //for std::move
#include <iostream>

int main()
{
    System system(0.0, 0.01); // Initialize the system with time 0.0 and dt 0.1
    Object object1,object2,object3; // Create an object
    //using explicit initialization for properties
    object1.motion.position = {0.0, 0.0, 0.0}; // Set the position of the object
    object1.motion.velocity = {0.0, 0.0, 1.0}; // Set the velocity of the object
    object1.setMass(1.0); // Set the mass of the object
    system.add_object(std::make_shared<Object>(object1)); // Add the object to the system

    object2.motion.position = {1.0, 0.0, 0.0}; // Set the position of the object
    object2.motion.velocity = {0.0, 0.0, -1.0}; // Set the velocity of the object
    object2.setMass(1.0); // Set the mass of the objectS
    system.add_object(std::make_shared<Object>(object2)); // Add the object to the system

    // object3.motion.position = {0.0, 0.0, 1.0}; // Set the position of the object
    // object3.motion.velocity = {1.0, 1.0, 0.0}; // Set the velocity of the object
    // object3.setMass(1.0); // Set the mass of the object
    // system.add_object(std::make_shared<Object>(object3)); // Add the object to the system

    for (int i = 0; i < 100000; ++i) // Update the system 10 times
    {
        system.accCalc(); // Calculate the accelerations based on forces
        system.update();
        system.display(); // Display the state of the system after each update
        //system.print_force(); // Print the forces acting on the objects
    }

    return 0;
}