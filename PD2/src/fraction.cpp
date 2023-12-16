#include "fraction.hpp"
#include <stdexcept>

Fraction::Fraction(int numerator, int denominator)
{
    if (denominator != 0)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }
    else
    {
        throw std::invalid_argument("Denominator must not be zero");
    }
}

Fraction::Fraction(const Fraction &source)
{
    this->numerator = source.numerator;
    this->denominator = source.denominator;
}

int Fraction::get_numerator() const
{
    return this->numerator;
}
int Fraction::get_denominator() const
{
    return this->denominator;
}
void Fraction::set_numerator(int numerator)
{
    this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
    if (denominator != 0)
    {
        this->denominator = denominator;
    }
    else
    {
        throw std::invalid_argument("Cannot set denominator to zero");
    }
}
double Fraction::get_value() const
{
    return static_cast<double>(this->numerator) / static_cast<double>(this->denominator);
}

Fraction &Fraction::operator++()
{
    this->numerator = this->numerator + this->denominator;
    return *this;
}

Fraction Fraction::operator++(int)
{
    Fraction old_fraction = *this;
    ++(*this);
    return old_fraction;
}

Fraction &Fraction::operator--()
{
    this->numerator = this->numerator - this->denominator;
    return *this;
}

Fraction Fraction::operator--(int)
{
    Fraction old_fraction = *this;
    --(*this);
    return old_fraction;
}

Fraction &Fraction::operator+=(const Fraction &other)
{
    numerator = numerator * other.denominator + other.numerator * denominator;
    denominator = denominator * other.denominator;
    return *this;
}

Fraction Fraction::operator+(const Fraction &other) const
{
    return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
}

Fraction &Fraction::operator-=(const Fraction &other)
{
    numerator = numerator * other.denominator - other.numerator * denominator;
    denominator = denominator * other.denominator;
    return *this;
}

Fraction Fraction::operator-(const Fraction &other) const
{
    return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
}

Fraction &Fraction::operator*=(const Fraction &other)
{
    numerator = numerator * other.numerator;
    denominator = denominator * other.denominator;
    return *this;
}

Fraction Fraction::operator*(const Fraction &other) const
{
    return Fraction(numerator * other.numerator, denominator * other.denominator);
}

Fraction &Fraction::operator/=(const Fraction &other)
{
    if (other.numerator != 0)
    {
        numerator = numerator * other.denominator;
        denominator = denominator * other.numerator;
        return *this;
    }
    else
    {
        throw std::invalid_argument("You cannot divide by 0");
    }
}

Fraction Fraction::operator/(const Fraction &other) const
{
    if (other.numerator != 0)
    {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }
    else
    {
        throw std::invalid_argument("You cannot divide by 0");
    }
}

bool Fraction::operator==(const Fraction &other) const
{
    double difference = get_value() - other.get_value();
    return difference > -0.00000001 && difference < 0.00000001;
}

bool Fraction::operator!=(const Fraction &other) const
{
    double difference = get_value() - other.get_value();
    return difference < -0.00000001 || difference > 0.00000001;
}

bool Fraction::operator==(const double value) const
{
    double difference = get_value() - value;
    return difference > -0.00000001 && difference < 0.00000001;
}

bool Fraction::operator!=(const double value) const
{
    double difference = get_value() - value;
    return difference < -0.00000001 || difference > 0.00000001;
}

bool Fraction::operator>(const Fraction &other) const
{
    return numerator * other.denominator > other.numerator * denominator;
}

bool Fraction::operator<(const Fraction &other) const
{
    return numerator * other.denominator < other.numerator * denominator;
}

bool Fraction::operator>=(const Fraction &other) const
{
    return numerator * other.denominator >= other.numerator * denominator;
}

bool Fraction::operator<=(const Fraction &other) const
{
    return numerator * other.denominator <= other.numerator * denominator;
}

Fraction Fraction::get_nth_power(int n) const
{
    Fraction operating_fraction = Fraction(*this);
    int final_numerator = 1;
    int final_denominator = 1;
    if (n < 0)
    {
        int temp = operating_fraction.denominator;
        operating_fraction.set_denominator(operating_fraction.numerator); // will throw exception if numerator is zero
        operating_fraction.set_numerator(temp);
        n = -n;
    }
    for (int i = 0; i < n; i++)
    {
        final_numerator = final_numerator * numerator;
        final_denominator = final_denominator * denominator;
    }
    operating_fraction.set_numerator(final_numerator);
    operating_fraction.set_denominator(final_denominator);
    return operating_fraction;
}

Fraction Fraction::get_inverse() const
{
    return Fraction(denominator, numerator); //
}

std::ostream &operator<<(std::ostream &os, const Fraction &fraction)
{
    os << fraction.numerator << "/" << fraction.denominator;
    return os;
}
