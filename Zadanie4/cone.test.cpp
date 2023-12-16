#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "cone.hpp"
#include <cmath>

TEST_CASE("Testing Writing class")
{
    Cone cone = Cone(1, 2);
    REQUIRE(cone.calculate_base_area() == M_PI);
    REQUIRE(cone.calculate_volume() == M_PI * 2 / 3);
    REQUIRE_THROWS_AS(cone.set_height(0), ZeroLengthException);
}