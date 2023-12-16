#include "unit.hpp"
#include "area.hpp"
#include <iostream>

Area::Area(double value, Unit *unit)
{
    if (value < 0)
    {
        throw std::invalid_argument("Area cannot be negative");
    }
    area_value = value;
    area_unit = unit;
};

Area::Area(){};

double Area::get_area_value()
{
    return area_value;
};

Unit *Area::get_area_unit()
{
    return area_unit;
};

void Area::set_area_value(double value)
{
    if (value < 0)
    {
        throw std::invalid_argument("Area cannot be negative");
    }
    area_value = value;
};

void Area::set_area_unit(Unit *unit)
{
    area_unit = unit;
};

void Area::print_area()
{
    std::cout << area_value << " " << area_unit->get_representation() << std::endl;
}