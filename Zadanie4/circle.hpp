#pragma once
#include <cmath>
#include "zero_length_exception.hpp"

class Circle{
    private:
    size_t radius;
    public:
    Circle(size_t radius);
    Circle();
    size_t get_radius() const;
    void set_radius(size_t radius);
    double calculate_area() const;
};