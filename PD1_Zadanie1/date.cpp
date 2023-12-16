#include <iostream>
#include "date.hpp"

Date::Date(int day_number, month_name name_of_month, int year_number)
{
    day = day_number;
    month = name_of_month;
    year = year_number;
}

Date::~Date()
{
}

int Date::get_day() const
{
    return day;
}

month_name Date::get_month() const
{
    return month;
}

int Date::get_year() const
{
    return year;
}

void Date::set_day(int day_number)
{
    day = day_number;
}

void Date::set_month(month_name name_of_month)
{
    month = name_of_month;
}

void Date::set_year(int year_number)
{
    year = year_number;
}

void Date::print_date()
{
    std::cout << day << "/" << int(month) + 1 << "/" << year << std::endl;
}
