#include "complex_number.hpp"
#include <iostream>

int main(){

    ComplexNumber first = ComplexNumber(2.0, 3.0);
    ComplexNumber second = ComplexNumber(4.0, 7.0);

    std::cout << first * second << std::endl;
    ComplexNumber numerator = ComplexNumber(8.0, 10.0);
    ComplexNumber denominator = ComplexNumber(4.0, 5.0);
    std::cout << numerator / denominator << std::endl;



}