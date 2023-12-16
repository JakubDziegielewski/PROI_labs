#include "unit.hpp"

Unit::Unit(double scale, std::string unit_representation)
{
    scale_to_m2 = scale;
    representation = unit_representation;
};

double Unit::get_scale_to_m2()
{
    return scale_to_m2;
};
std::string Unit::get_representation()
{
    return representation;
};
