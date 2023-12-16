#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <stdexcept>
#include "fraction.hpp"

TEST_CASE("Operations on fractions")
{
    Fraction fraction_one = Fraction(1, 2);
    Fraction fraction_two = Fraction(1, 3);

    REQUIRE(fraction_one + fraction_two == Fraction(5, 6));
    REQUIRE(fraction_one - fraction_two == Fraction(1, 6));
    REQUIRE(fraction_one * fraction_two == Fraction(1, 6));
    REQUIRE(fraction_one / fraction_two == Fraction(3, 2));
}

TEST_CASE("Comparing fractions")
{
    REQUIRE(Fraction(1, 1) == Fraction(1, 1));
    REQUIRE(Fraction(10, 5) == Fraction(2, 1));
    REQUIRE(Fraction(5, 7) == Fraction(25, 35));
    REQUIRE(Fraction(-8, 18) == Fraction(20, -45));
    REQUIRE(Fraction(0, -10) == Fraction(0, 20));
    REQUIRE(Fraction(100, 10) != Fraction(200, 21));

    REQUIRE(Fraction(9, 10) > Fraction(8, 10));
    REQUIRE(Fraction(3, 4) > Fraction(2, 3));
    REQUIRE(Fraction(1, 3) < Fraction(2, 3));
    REQUIRE(Fraction(5, 6) < Fraction(18, 20));

    REQUIRE(Fraction(10, 12) >= Fraction(5, 6));
    REQUIRE(Fraction(20, 12) >= Fraction(5, 6));

    REQUIRE(Fraction(-8, 2) >= Fraction(-21, 3));
    REQUIRE(Fraction(8, 2) <= Fraction(16, 4));
}

TEST_CASE("Testing comparing with double")
{
    REQUIRE(Fraction(25, 7) == 3.57142857142);
    REQUIRE(Fraction(1, 999999999) == 0.0);
    REQUIRE(Fraction(20, 10) != 1.99);
}

TEST_CASE("Test incrementing and decrementing")
{
    Fraction fraction_one = Fraction(2, 7);
    Fraction fraction_two = Fraction(9, 7);
    REQUIRE(++fraction_one == fraction_two);
    REQUIRE(fraction_one++ == fraction_two);
    REQUIRE(--fraction_one-- == fraction_two);
    REQUIRE(fraction_one-- == fraction_two);
    REQUIRE(fraction_one == Fraction(2, 7));
}



TEST_CASE("Test throwing exception when denomnator equals 0")
{
    REQUIRE_THROWS_AS(Fraction(7, 0), std::invalid_argument);
    Fraction fractrion = Fraction(1, 1);
    REQUIRE_THROWS_AS(fractrion.set_denominator(0), std::invalid_argument);
    REQUIRE_THROWS_AS(Fraction(1, 1) / Fraction(0, 3), std::invalid_argument);
    REQUIRE_THROWS_AS(Fraction(1, 1) /= Fraction(0, 3), std::invalid_argument);
    REQUIRE_THROWS_AS(Fraction(0, 1).get_inverse(), std::invalid_argument);
}

TEST_CASE("Test getting nth power")
{
    Fraction fraction_one = Fraction(1, 2);
    Fraction fraction_two = Fraction(-7, 9);

    REQUIRE(fraction_one.get_nth_power(10) == Fraction(1, 1024));
    REQUIRE(fraction_two.get_nth_power(3) == Fraction(-343, 729));
    REQUIRE(fraction_two.get_nth_power(2) == Fraction(-49, -81));
    REQUIRE(fraction_one.get_inverse().get_nth_power(5) == Fraction(32, 1));
}