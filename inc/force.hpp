#ifndef __FORCE_HPP__
#define __FORCE_HPP__

#include <object.hpp>
#include <memory>

class Force
{
public:
    std::shared_ptr<Object> object_1 {},object_2 {}; // Pointer to the object that the force is acting on
    Force() = delete; //Force must be initialized with two objects
    Force(std::shared_ptr<Object> obj1,std::shared_ptr<Object> obj2) : object_1{obj1}, object_2{obj2} {} // Constructor to initialize the force with two objects
    virtual void effect() = 0; // Pure virtual function to get the effect of the force
};

class Gravity : public Force
{
public:
    using Force::Force; // Inherit constructors from Force
    void effect() override;
private:
    static inline const double G = 1.0;
};

#endif 