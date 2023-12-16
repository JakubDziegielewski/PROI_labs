#include "figure.hpp"
#include "invalid_color_exception.hpp"

Figure::Figure(size_t x, size_t y, std::string stroke_color, std::string fill_color) : Element(x, y, stroke_color)
{
    if (!find_color(fill_color))
    {
        throw InvalidColorException(fill_color);
    }
     this-> fill_color = fill_color;
}

Figure::Figure()
{
}

std::string Figure::get_fill_color() const{
    return this->fill_color;
}

void Figure::set_fill_color(std::string fill_color){
    if (!find_color(fill_color))
    {
        throw InvalidColorException(fill_color);
    }
    this->fill_color = fill_color;
}

