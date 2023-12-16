#include "geometric_sequence.hpp"
#include <cmath>
#include <iostream>

GeometricSequence::GeometricSequence(double starting_a1, double starting_q)
{
    a1 = starting_a1;
    q = starting_q;
}

double GeometricSequence::get_a1() const
{
    return a1;
}

double GeometricSequence::get_q() const
{
    return q;
}

void GeometricSequence::set_a1(double new_a1)
{
    a1 = new_a1;
}

void GeometricSequence::set_q(double new_q)
{
    q = new_q;
}

double GeometricSequence::get_nth_element(int n) const
{
    if (n > 0)
    {
        return a1 * std::pow(q, n - 1);
    }
    else
    {
        throw std::invalid_argument("Index must be positive");
    }
}

double GeometricSequence::get_sum_of_first_n_elements(int n) const
{
    if (n > 0)
    {
        if (q == 1.0)
        {
            return a1 * n;
        }
        else
        {
            return a1 * (1 - std::pow(q, n)) / (1 - q);
        }
    }
    else
    {
        throw std::invalid_argument("Index must be positive");
    }
}