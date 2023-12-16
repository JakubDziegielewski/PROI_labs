#pragma once
#include "figure.hpp"
class Circle : public Figure
{
private:
    size_t radius;

public:
    Circle(size_t radius, size_t x, size_t y, std::string stroke_color, std::string fill_color);
    size_t get_radius() const;
    void set_radius(size_t radius);
    void write_in_svg_file(std::ofstream &svg_file) const;
};