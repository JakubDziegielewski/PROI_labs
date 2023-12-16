#pragma once
#include <stdexcept>

class ZeroLengthException : public std::invalid_argument
{
private:
    size_t length;
public:
    ZeroLengthException(size_t length);
    size_t get_length() const;
};