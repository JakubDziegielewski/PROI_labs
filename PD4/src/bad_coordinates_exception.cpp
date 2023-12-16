#include "bad_coordinates_exception.hpp"

BadCoordinatesException::BadCoordinatesException(size_t x, size_t y) : std::invalid_argument("Coordinates are out of scope for the drawing"), x(x), y(y)
{
}

size_t BadCoordinatesException::get_x() const
{
    return this->x;
}

size_t BadCoordinatesException::get_y() const
{
    return this->y;
}