#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <stdexcept>
#include "complex_number.hpp"

TEST_CASE("Checking if operations are correct")
{
    ComplexNumber one = ComplexNumber(10.0, -4.0);
    ComplexNumber two = ComplexNumber(2.0, 0.0);

    ComplexNumber three = ComplexNumber(0.0, 3.0);
    REQUIRE(one * two == ComplexNumber(20.0, -8.0));
    REQUIRE(one * three == ComplexNumber(12.0, 30.0));
    REQUIRE(two * three == ComplexNumber(0.0, 6.0));
    one *= two;
    REQUIRE(one == ComplexNumber(20.0, -8.0));
    REQUIRE(one / two == ComplexNumber(10.0, -4.0));
    one /= two;
    REQUIRE(one == ComplexNumber(10.0, -4.0));
    
}

TEST_CASE("Checking if exception is thrown")
{
    ComplexNumber one = ComplexNumber(1.0, 1.0);
    ComplexNumber two = ComplexNumber(0.0, 0.0);
    REQUIRE_THROWS_AS(one/two, std::invalid_argument);

}