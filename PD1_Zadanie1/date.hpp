#pragma once
#include "month_name.hpp"

class Date
{
private:
    int day;
    month_name month;
    int year;

public:
    Date(int day_number, enum month_name, int year_number);
    ~Date();
    int get_day() const;
    month_name get_month() const;
    int get_year() const;
    void set_day(int day_number);
    void set_month(enum month_name);
    void set_year(int year_number);
    void print_date();
};