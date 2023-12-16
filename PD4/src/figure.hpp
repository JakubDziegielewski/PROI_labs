#pragma once
#include "element.hpp"

class Figure : public Element{
protected:
    std::string fill_color;

public:
    Figure(size_t x, size_t y, std::string stroke_color, std::string fill_color);
    Figure();
    ~Figure() = default;
    virtual void write_in_svg_file(std::ofstream &svg_file) const = 0;
    std::string get_fill_color() const;
    void set_fill_color(std::string fill_color);
};

