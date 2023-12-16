#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <optional>

class Element
{
protected:
    size_t x;
    size_t y;
    std::string stroke_color;
    const static std::vector<std::string> colors;
    bool find_color(const std::string &color) const;

public:
    Element(size_t x, size_t y, std::string stroke_color);
    Element();
    ~Element() = default;
    size_t get_x() const;
    size_t get_y() const;
    std::string get_stroke_color() const;
    void set_x(size_t x);
    void set_y(size_t y);
    void set_stroke_color(std::string stroke_color);
    virtual void write_in_svg_file(std::ofstream &svg_file) const = 0;
    
};
