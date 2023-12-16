#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "cylinder.hpp"
#include <cmath>

TEST_CASE("Testing Writing class")
{
    Cylinder cylinder = Cylinder(1, 2);
    REQUIRE(cylinder.calculate_base_area() == M_PI);
    REQUIRE(cylinder.calculate_volume() == M_PI * 2);
    REQUIRE_THROWS_AS(cylinder.set_base_radius(0), ZeroLengthException);
}