#pragma once
#include "date.hpp"

class DateValidator
{
private:
public:
    DateValidator();
    bool validate_date(int day_number, month_name name_of_month, int year_number);
};