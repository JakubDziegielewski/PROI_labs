#include "circle.hpp"

Circle::Circle(size_t radius, size_t x, size_t y, std::string stroke_color, std::string fill_color) : Figure(x, y, stroke_color, fill_color), radius(radius)
{
}

size_t Circle::get_radius() const{
    return this->radius;
}

void Circle::set_radius(size_t radius){
    this->radius = radius;
}

void Circle::write_in_svg_file(std::ofstream &svg_file) const{
    svg_file
        << "<circle cx=\"" << this->x
        << "\" cy=\"" << this->y
        << "\" r=\"" << this->radius
        << "\" fill=\"" << this->fill_color
        << "\" stroke = \"" << this->stroke_color << "\"/>"
        << std::endl;
}