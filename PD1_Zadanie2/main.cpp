#include <iostream>
#include "unit.hpp"
#include "area.hpp"
#include "area_unit_converter.hpp"
#include <limits>

Unit mm2 = Unit(1000000, "mm^2");
Unit cm2 = Unit(10000, "cm^2");
Unit dm2 = Unit(100, "dm^2");
Unit m2 = Unit(1, "m^2");
Unit km2 = Unit(0.000001, "km^2");
Unit ac = Unit(0.000247105, "ac");
Unit a = Unit(0.01, "a");
Unit ha = Unit(0.0001, "ha");

Area area = Area();
Unit *unit;
AreaUnitConverter converter = AreaUnitConverter();
double user_input;

void select_unit()
{
    std::cout << "\nChoose a unit:\n";
    std::cout << "1. mm^2\n";
    std::cout << "2. cm^2\n";
    std::cout << "3. dm^2\n";
    std::cout << "4. m^2\n";
    std::cout << "5. km^2\n";
    std::cout << "6. ac^2\n";
    std::cout << "7. a^2\n";
    std::cout << "8. ha^2\n";
    std::cout << "\nEnter a number of your selection:";
    std::cin >> user_input;
    if (std::cin)
    {
        switch (int(user_input))
        {
        case 1:
            unit = &mm2;
            break;
        case 2:
            unit = &cm2;
            break;
        case 3:
            unit = &dm2;
            break;
        case 4:
            unit = &m2;
            break;
        case 5:
            unit = &km2;
            break;
        case 6:
            unit = &ac;
            break;
        case 7:
            unit = &a;
            break;
        case 8:
            unit = &ha;
            break;
        default:
            std::cout << "You did not enter a correct number\n";
            break;
        }
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');
    }
    else
    {
        std::cout << "You did not enter a number\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');
    }
}

void enter_new_area()
{
    std::cout << "Enter the new Area: ";
    std::cin >> user_input;
    if (std::cin)
    {
        area.set_area_value(user_input);
        select_unit();
        area.set_area_unit(unit);
    }
    else
    {
        std::cout << "You did not enter a number\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');
    }
}

void change_unit()
{
    select_unit();
    std::cout << "\nBefore the unit change: ";
    area.print_area();
    converter.convert_area_unit(&area, unit);
    std::cout << "After the unit change: ";
    area.print_area();
}

int main()
{
    enter_new_area();
    while (user_input != -1)
    {
        std::cout << "\nSelect your action:\n";
        std::cout << "1. Enter a new area\n";
        std::cout << "2. Change the unit\n";
        std::cout << "3. Print the curret area\n";
        std::cout << "-1. Exit\n";

        std::cin >> user_input;
        if (std::cin)
        {
            switch (int(user_input))
            {
            case 1:
                enter_new_area();
                break;
            case 2:
                change_unit();
                break;
            case 3:
                std::cout << "\nCurrent Area: ";
                area.print_area();
                break;
            case -1:
                std::cout << "\nExiting...\n";
                break;
            default:
                std::cout << "You did not select a valid option\n";
                break;
            }
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        }
        else
        {
            std::cout << "You did not enter a number\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        }
    }
    return 0;
}