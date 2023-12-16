#pragma once
#include "figure.hpp"

class Rectangle : public Figure
{
private:
    size_t width;
    size_t height;

public:
    Rectangle(size_t width, size_t height, size_t x, size_t y, std::string stroke_color, std::string fill_color);
    size_t get_width() const;
    size_t get_height() const;
    void set_width(size_t width);
    void set_height(size_t height);
    void write_in_svg_file(std::ofstream &svg_file) const;
};