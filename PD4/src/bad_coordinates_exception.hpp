#pragma once
#include <stdexcept>

class BadCoordinatesException : public std::invalid_argument
{
private:
    size_t x;
    size_t y;

public:
    BadCoordinatesException(size_t x, size_t y);
    size_t get_x() const;
    size_t get_y() const;
};