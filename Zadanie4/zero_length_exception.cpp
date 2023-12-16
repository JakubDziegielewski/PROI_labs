#include "zero_length_exception.hpp"

ZeroLengthException::ZeroLengthException(size_t length) : std::invalid_argument("Length cannot be zero"), length(length)
{
}

size_t ZeroLengthException::get_length() const
{
    return length;
}