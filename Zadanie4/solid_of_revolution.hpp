#pragma once
#include <iostream>
#include "circle.hpp"
#include "zero_length_exception.hpp"
class SolidOfRevolution
{
protected:
    Circle base;
    size_t height;

public:
    SolidOfRevolution(size_t base_radius, size_t height);
    SolidOfRevolution();
    //virtual ~SolidOfRevolution() = 0;
    Circle get_base() const;
    size_t get_height() const;
    void set_base_radius(size_t radius);
    void set_height(size_t height);
    double calculate_base_area() const;
    virtual double calculate_volume() const = 0;
};