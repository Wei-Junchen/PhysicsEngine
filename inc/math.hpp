#ifndef __MATH_HPP__
#define __MATH_HPP__

#include <cmath>
#include <iostream>

namespace engine
{
    struct vector3d
    {
        double _1, _2, _3;
    
        vector3d(double x = 0.0, double y = 0.0, double z = 0.0) : _1(x), _2(y), _3(z) {}
        vector3d(const vector3d& other) : _1(other._1), _2(other._2), _3(other._3) {}
        void operator=(const vector3d& other)
        {
            _1 = other._1;
            _2 = other._2;
            _3 = other._3;
        }
        void operator=(vector3d&& other) noexcept
        {
            _1 = other._1;
            _2 = other._2;
            _3 = other._3;
        }
        vector3d operator*(double scalar) const { return {_1 * scalar, _2 * scalar, _3 * scalar}; }
        //cross multiplication
        vector3d cross(const vector3d& other) const { return {_2 * other._3 - _3 * other._2, _3 * other._1 - _1 * other._3, _1 * other._2 - _2 * other._1}; }
        //dot multiplication
        double dot(const vector3d& other) const { return _1 * other._1 + _2 * other._2 + _3 * other._3; }
        vector3d operator+(const vector3d& other) const { return {_1 + other._1, _2 + other._2, _3 + other._3}; }
        vector3d operator-(const vector3d& other) const { return {_1 - other._1, _2 - other._2, _3 - other._3}; }
        void operator+=(const vector3d& other) {_1+=other._1; _2+=other._2;_3+=other._3;}

        std::ostream& operator<<(std::ostream& os) const
        {
            os << "Vector3d(" << _1 << ", " << _2 << ", " << _3 << ")";
            return os;
        }

        friend std::ostream& operator<<(std::ostream& os, const vector3d& vec)
        {
            os << "Vector3d(" << vec._1 << ", " << vec._2 << ", " << vec._3 << ")";
            return os;
        }
    };

    inline vector3d operator*(double scalar,vector3d other)
    {
        return {other._1*scalar,other._2*scalar,other._3*scalar};
    }


}


#endif