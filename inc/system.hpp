#ifndef __SYSTEM_HPP__
#define __SYSTEM_HPP__

#include "vector"
#include "object.hpp"
#include <iostream>
#include "force.hpp" // Assuming force.hpp is in the same directory

class System
{
private:
    double time{};
    double dt{};
    std::vector<std::shared_ptr<Object>> objects {}; // Assuming Object is defined in object.hpp
    std::vector<std::unique_ptr<Force>> forces {}; // Assuming Force is defined in force.hpp
public:
    System() = default;
    System(double t, double delta) : time(t), dt(delta) {}
    double get_time() const { return time; }
    void set_time(double t) { time = t; }
    void set_dt(double delta) { dt = delta; }

    void update();
    void accCalc();
    void display() const
    {
        for (const auto& object : objects)
        {
            // Display object properties here
            std::cout <<std::hex<<std::showbase<<object<<std::dec<<std::noshowbase<<" : "<<object->motion.position <<" at: "<<time<< std::endl;
        }
    }

    void add_object(std::shared_ptr<Object> object) 
    { 
        objects.push_back(object);
        for(int i = 0;i<objects.size()-1;i++)
        {
            //print_force();
            forces.push_back(std::make_unique<Gravity>(objects[objects.size()-1], objects[i])); // Assuming Gravity is defined in force.hpp
        }
    }

    //void add_force(Force&& force) { forces.push_back(std::move(force)); } // Assuming Force is defined in force.hpp
    void print_force()
    {
        for (const auto& force : forces)
        {
            // Display force properties here
            std::cout << "Force between objects: " << force->object_1->motion.position._1 << ", " << force->object_1->motion.position._2 << ", " << force->object_1->motion.position._3 << " and "
                      << force->object_2->motion.position._1 << ", " << force->object_2->motion.position._2 << ", " << force->object_2->motion.position._3 << std::endl;
        }
    }
};

#endif
