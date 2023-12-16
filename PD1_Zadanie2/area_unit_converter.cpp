#include "unit.hpp"
#include "area_unit_converter.hpp"
#include "area.hpp"
#include <map>

AreaUnitConverter::AreaUnitConverter(){};

void AreaUnitConverter::convert_area_unit(Area *area, Unit *unit_to_convert_into)
{
    double scale = unit_to_convert_into->get_scale_to_m2() / area->get_area_unit()->get_scale_to_m2();
    area->set_area_value(area->get_area_value() * scale);
    area->set_area_unit(unit_to_convert_into);
};