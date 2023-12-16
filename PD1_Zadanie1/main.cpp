#include "date.hpp"
#include <iostream>
#include "date_validator.hpp"

int main()
{
    DateValidator date_validator = DateValidator();
    const int d[] = {1, 29, 29, 29, 29, 31, 17, 30, 31, 14};
    const month_name m[] = {month_name::Jan, month_name::Feb, month_name::Feb, month_name::Feb, month_name::Feb, month_name::Mar, month_name::Mar, month_name::Apr, month_name::Apr, month_name::Sep};
    const int y[] = {2023, 2020, 2021, 2100, 2000, 2023, 2023, 2030, 2001, 1999};
    for (size_t i = 0; i < 10; i++)
    {
        if (date_validator.validate_date(d[i], m[i], y[i]))
        {
            Date date = Date(d[i], m[i], y[i]);
            date.print_date();
            if (date_validator.validate_date(d[i] + 1, m[i], y[i]))
            {
                date.set_day(d[i] + 1);
                date.print_date();
            }
            else
            {
                std::cout << (d[i] + 1) << "/" << int(m[i]) + 1 << "/" << y[i] << " is not a valid date\n";
            }
        }
        else
        {
            std::cout << d[i] << "/" << int(m[i]) + 1 << "/" << y[i] << " is not a valid date\n";
        };
    }

    return 0;
}