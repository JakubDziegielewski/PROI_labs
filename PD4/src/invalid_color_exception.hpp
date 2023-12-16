#pragma once
#include <stdexcept>

class InvalidColorException : public std::invalid_argument
{
private:
    std::string color;
public:
    InvalidColorException(std::string color);
    std::string get_color() const;
};