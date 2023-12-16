#include "drawing.hpp"
#include "bad_coordinates_exception.hpp"
Drawing::Drawing(size_t width, size_t height) : width(width), height(height)
{
    this->elements = std::list<std::unique_ptr<Element>>();
}

size_t Drawing::get_width()
{
    return this->width;
}
size_t Drawing::get_height()
{
    return this->height;
}
void Drawing::set_width(size_t width)
{
    this->width = width;
}
void Drawing::set_height(size_t height)
{
    this->height = height;
}

void Drawing::add_line(size_t x1, size_t y1, size_t x2, size_t y2, std::string stroke_color)
{
    if (x1 >= this->width || y1 >= this->height)
    {
        throw BadCoordinatesException(x1, y1);
    }
    std::unique_ptr<Line> added_line = std::make_unique<Line>(x1, y1, x2, y2, stroke_color);
    elements.push_back(std::move(added_line));
}
void Drawing::add_circle(size_t radius, size_t x, size_t y, std::string stroke_color, std::string fill_color)
{
    if (x >= this->width || y >= this->height)
    {
        throw BadCoordinatesException(x, y);
    }
    std::unique_ptr<Circle> added_circle = std::make_unique<Circle>(radius, x, y, stroke_color, fill_color);
    elements.push_back(std::move(added_circle));
}
void Drawing::add_rectangle(size_t width, size_t height, size_t x, size_t y, std::string stroke_color, std::string fill_color)
{
    if (x >= this->width || y >= this->height)
    {
        throw BadCoordinatesException(x, y);
    }
    std::unique_ptr<Rectangle> added_rectangle = std::make_unique<Rectangle>(width, height, x, y, stroke_color, fill_color);
    elements.push_back(std::move(added_rectangle));
}
void Drawing::add_writing(std::string text, size_t font_size, std::string text_anchor, size_t x, size_t y, std::string stroke_color, std::string fill_color)
{
    if (x >= this->width || y >= this->height)
    {
        throw BadCoordinatesException(x, y);
    }
    std::unique_ptr<Writing> added_writing = std::make_unique<Writing>(text, font_size, text_anchor, x, y, stroke_color, fill_color);
    elements.push_back(std::move(added_writing));
}
void Drawing::save_to_svg_file(std::string file_name)
{
    std::ofstream svg_file(file_name);
    if (!svg_file)
    {
        throw std::invalid_argument("Cannot write to the file");
    }

    svg_file << "<svg version=\"1.1\"width=\"" << this->width << "\" height=\"" << this->height << "\"xmlns=\"http://www.w3.org/2000/svg\">\n";
    for (const auto &element_ptr : elements)
    {
        element_ptr->write_in_svg_file(svg_file);
    }
    svg_file << "</svg>";
}