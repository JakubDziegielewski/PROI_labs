#pragma once
#include <list>
#include <memory>
#include <fstream>
#include "line.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "writing.hpp"

class Drawing
{
private:
    std::list<std::unique_ptr<Element>> elements;
    size_t width;
    size_t height;

public:
    Drawing(size_t width, size_t height);
    size_t get_width();
    size_t get_height();
    void set_width(size_t width);
    void set_height(size_t height);
    void add_line(size_t x1, size_t y1, size_t x2, size_t y2, std::string stroke_color);
    void add_circle(size_t radius, size_t x, size_t y, std::string stroke_color, std::string fill_color);
    void add_rectangle(size_t width, size_t height, size_t x, size_t y, std::string stroke_color, std::string fill_color);
    void add_writing(std::string text, size_t font_size, std::string text_anchor, size_t x, size_t y, std::string stroke_color, std::string fill_color);
    void save_to_svg_file(std::string file_name);
};
