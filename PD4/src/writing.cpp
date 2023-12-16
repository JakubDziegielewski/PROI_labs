#include "writing.hpp"

Writing::Writing(std::string text, size_t font_size, std::string text_anchor, size_t x, size_t y, std::string stroke_color, std::string fill_color)
    : Figure(x, y, stroke_color, fill_color), text(text), font_size(font_size), text_anchor(text_anchor)
{
}

std::string Writing::get_text() const
{
    return this->text;
}

size_t Writing::get_font_size() const
{
    return this->font_size;
}

std::string Writing::get_text_anchor() const
{
    return this->text_anchor;
}

void Writing::set_text(std::string text)
{
    this->text = text;
}
void Writing::set_font_size(size_t font_size)
{
    this->font_size = font_size;
}

void Writing::set_text_anchor(std::string text_anchor)
{
    this->text_anchor = text_anchor;
}

void Writing::write_in_svg_file(std::ofstream &svg_file) const
{
    svg_file
        << "<text x=\"" << this->x
        << "\" y=\"" << this->y
        << "\" font-size=\"" << this->font_size
        << "\" text-anchor=\"" << this->text_anchor
        << "\" fill=\"" << this->fill_color
        << "\" stroke = \"" << this->stroke_color
        << "\">" << this->text
        <<"</text>"
        << std::endl;
}