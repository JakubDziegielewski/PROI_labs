#include "geometric_sequence.hpp"
#include <iostream>

int main()
{

    std::cout << "Pass the first element of the geometric sequence: ";

    double user_input;

    std::cin >> user_input;

    double a1 = user_input;

    std::cout << "\nPass the common ratio: ";

    std::cin >> user_input;

    double q = user_input;

    GeometricSequence g1 = GeometricSequence(a1, q);

    int user_in;
    std::cout << "\nPass the n for the calculation: ";

    std::cin >> user_in;
    int n = user_in;

    double nth_element = g1.get_nth_element(n);
    double sum = g1.get_sum_of_first_n_elements(n);

    std::cout << "\n"
              << n << "th element: " << nth_element << std::endl;
    std::cout << "sum of the first " << n << " elements: " << sum << std::endl;

    return 0;
}