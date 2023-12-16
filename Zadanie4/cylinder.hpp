#pragma once
#include "solid_of_revolution.hpp"

class Cylinder : public SolidOfRevolution{
    public:
    Cylinder(size_t base_radius, size_t height);
    ~Cylinder() = default;
    double calculate_volume() const;
};