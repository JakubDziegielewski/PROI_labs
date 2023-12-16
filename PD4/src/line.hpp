#pragma once
#include <iostream>
#include "element.hpp"

class Line : public Element
{
private:
    size_t x2;
    size_t y2;

public:
    Line(size_t x1, size_t y1, size_t x2, size_t y2, std::string stroke_color);
    size_t get_x2();
    size_t get_y2();
    void set_x2(size_t x2);
    void set_y2(size_t y2);
    void write_in_svg_file(std::ofstream &svg_file) const;
};