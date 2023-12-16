#pragma once
#include "unit.hpp"
#include "area.hpp"
#include <map>

class AreaUnitConverter{
private:


public:
AreaUnitConverter();
void convert_area_unit(Area *area, Unit *unit_to_convert_into);
};
