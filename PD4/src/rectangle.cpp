#include "rectangle.hpp"

Rectangle::Rectangle(size_t width, size_t height, size_t x, size_t y, std::string stroke_color, std::string fill_color)
    : Figure(x, y, stroke_color, fill_color), width(width), height(height)
{
}

size_t Rectangle::get_width() const
{
    return this->width;
}

size_t Rectangle::get_height() const
{
    return this->height;
}

void Rectangle::set_width(size_t width)
{
    this->width = width;
}
void Rectangle::set_height(size_t height)
{
    this->height = height;
}

void Rectangle::write_in_svg_file(std::ofstream &svg_file) const
{
    svg_file
        << "<rect x=\"" << this->x
        << "\" y=\"" << this->y
        << "\" width=\"" << this->width
        << "\" height=\"" << this->height
        << "\" fill=\"" << this->fill_color
        << "\" stroke = \"" << this->stroke_color << "\"/>"
        << std::endl;
}