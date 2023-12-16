#include "circle.hpp"

Circle::Circle(size_t radius)
{
    if (radius == 0)
    {
        throw ZeroLengthException(radius);
    }
    this->radius = radius;
}

Circle::Circle() {}

size_t Circle::get_radius() const
{
    return this->radius;
}

void Circle::set_radius(size_t radius)
{
    if (radius == 0)
    {
        throw ZeroLengthException(radius);
    }
    this->radius = radius;
}

double Circle::calculate_area() const
{
    return M_PI * pow(this->radius, 2);
}