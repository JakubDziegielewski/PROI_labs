#pragma once
#include <string>

class Unit
{
private:
    double scale_to_m2;
    std::string representation;

public:
    Unit(double scale, std::string unit_representation);
    double get_scale_to_m2();
    std::string get_representation();
};
