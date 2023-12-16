#pragma once
#include <iostream>

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator);
    Fraction(const Fraction &source);
    int get_numerator() const;
    int get_denominator() const;
    void set_numerator(int numerator);
    void set_denominator(int denominator);
    double get_value() const;

    Fraction &operator++();
    Fraction operator++(int);

    Fraction &operator--();
    Fraction operator--(int);

    Fraction &operator+=(const Fraction &other);
    Fraction operator+(const Fraction &otehr) const;

    Fraction &operator-=(const Fraction &other);
    Fraction operator-(const Fraction &otehr) const;

    Fraction &operator*=(const Fraction &other);
    Fraction operator*(const Fraction &otehr) const;

    Fraction &operator/=(const Fraction &other);
    Fraction operator/(const Fraction &otehr) const;

    bool operator==(const Fraction &other) const;
    bool operator!=(const Fraction &other) const;
    bool operator==(const double value) const;
    bool operator!=(const double value) const;

    bool operator>(const Fraction &other) const;
    bool operator<(const Fraction &other) const;

    bool operator>=(const Fraction &other) const;
    bool operator<=(const Fraction &other) const;

    Fraction get_nth_power(int n) const;
    Fraction get_inverse() const;

    friend std::ostream &operator<<(std::ostream &os, const Fraction &fraction);
};

std::ostream &operator<<(std::ostream &os, const Fraction &fraction);
