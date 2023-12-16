#include "invalid_color_exception.hpp"

InvalidColorException::InvalidColorException(std::string color) : std::invalid_argument(color + " is not a defined color"), color(color)
{
}

std::string InvalidColorException::get_color() const
{
    return this->color;
}