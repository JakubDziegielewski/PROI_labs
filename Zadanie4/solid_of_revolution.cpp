#include "solid_of_revolution.hpp"

SolidOfRevolution::SolidOfRevolution(size_t base_radius, size_t height)
{
    if (base_radius == 0 || height == 0)
    {
        throw ZeroLengthException(base_radius);
    }
    this->base = Circle(base_radius);
    this->height = height;
}

SolidOfRevolution::SolidOfRevolution()
{
}
Circle SolidOfRevolution::get_base() const
{
    return this->base;
}
size_t SolidOfRevolution::get_height() const
{
    return this->height;
}
void SolidOfRevolution::set_base_radius(size_t radius)
{
    if (radius == 0)
    {
        throw ZeroLengthException(radius);
    }
    this->base.set_radius(radius);
}
void SolidOfRevolution::set_height(size_t height)
{
    if (height == 0)
    {
        throw ZeroLengthException(height);
    }
    this->height = height;
}
double SolidOfRevolution::calculate_base_area() const
{
    return this->base.calculate_area();
}