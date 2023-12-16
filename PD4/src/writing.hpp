#pragma once
#include "figure.hpp"

class Writing : public Figure
{
private:
    std::string text;
    size_t font_size;
    std::string text_anchor;

public:
    Writing(std::string text, size_t font_size, std::string text_anchor, size_t x, size_t y, std::string stroke_color, std::string fill_color);
    std::string get_text() const;
    size_t get_font_size() const;
    std::string get_text_anchor() const;
    void set_text(std::string text);
    void set_font_size(size_t font_size);
    void set_text_anchor(std::string text_anchor);
    void write_in_svg_file(std::ofstream &svg_file) const;
};