#include "element.hpp"
#include <algorithm>
#include "invalid_color_exception.hpp"

const std::vector<std::string> Element::colors = {"red", "blue", "white", "black", "None"};

bool Element::find_color(const std::string &color) const
{
    return std::find(colors.begin(), colors.end(), color) != colors.end();
}

Element::Element(size_t x, size_t y, std::string stroke_color) : x(x), y(y)
{
    if (!find_color(stroke_color))
    {
        throw InvalidColorException(stroke_color);
    }
    this->stroke_color = stroke_color;
}

Element::Element()
{
}

size_t Element::get_x() const
{
    return this->x;
}

size_t Element::get_y() const
{
    return this->y;
}

std::string Element::get_stroke_color() const
{
    return this->stroke_color;
}

void Element::set_x(size_t x)
{
    this->x = x;
}

void Element::set_y(size_t y)
{
    this->y = y;
}

void Element::set_stroke_color(std::string stroke_color)
{
    if (!find_color(stroke_color))
    {
        throw InvalidColorException(stroke_color);
    }
    this->stroke_color = stroke_color;
}
