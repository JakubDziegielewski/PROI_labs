#include "date_validator.hpp"
#include "date.hpp"

DateValidator::DateValidator(){};

bool DateValidator::validate_date(int day_number, month_name name_of_month, int year_number)
{
    int max_days_of_month[] = {31,
                               29,
                               31,
                               30,
                               31,
                               30,
                               31,
                               31,
                               30,
                               31,
                               30,
                               31};
    if (year_number % 4 != 0 || (year_number % 100 == 0 && year_number % 400 != 0))
    {
        max_days_of_month[1] = 28;
    };

    return day_number <= max_days_of_month[int(name_of_month)] && day_number > 0;
}