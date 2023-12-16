#include "line.hpp"

Line::Line(size_t x1, size_t y1, size_t x2, size_t y2, std::string stroke_color) : Element(x1, y1, stroke_color), x2(x2), y2(y2)
{
}

size_t Line::get_x2()
{
    return this->x2;
}

size_t Line::get_y2()
{
    return this->y2;
}

void Line::set_x2(size_t x2)
{
    this->x2 = x2;
}

void Line::set_y2(size_t y2)
{
    this->y2 = y2;
}

void Line::write_in_svg_file(std::ofstream &svg_file) const
{
    svg_file
        << "<line x1=\"" << this->x
        << "\" y1=\"" << this->y
        << "\" x2=\"" << this->x2
        << "\" y2=\"" << this->y2
        << "\" stroke = \"" << this->stroke_color << "\"/>"
        << std::endl;

}
