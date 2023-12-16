#pragma once
#include "unit.hpp"
#include <map>
#include <string>

class Area
{
private:
    double area_value;
    Unit *area_unit;

public:
    Area(double value, Unit *unit);
    Area();
    double get_area_value();
    Unit *get_area_unit();
    void set_area_value(double value);
    void set_area_unit(Unit *unit);
    void print_area();
};
