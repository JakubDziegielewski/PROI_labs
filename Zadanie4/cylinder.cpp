#include "cylinder.hpp"

Cylinder::Cylinder(size_t base_radius, size_t height) : SolidOfRevolution(base_radius, height)
{
}

double Cylinder::calculate_volume() const{
    return this->base.calculate_area() * this->height;
}