#include <iostream>
#include "src/fraction.hpp"

int main()
{
    Fraction fraction_one = Fraction(1, 2);
    Fraction fraction_two = Fraction(1, 3);
    std::cout << fraction_one << std::endl;
    std::cout << fraction_two << std::endl;
    std::cout << (fraction_one + fraction_two).get_value() << std::endl;
    std::cout << fraction_one.get_inverse().get_value() << std::endl;
    const double A = 3.57142857142;
    std::cout << (Fraction(25, 7) == A) << std::endl;
    return 0;
}