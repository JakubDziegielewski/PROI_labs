#define CATCH_CONFIG_MAIN
#include "circle.hpp"
#include "invalid_color_exception.hpp"
#include <catch2/catch.hpp>


TEST_CASE("Testing Circle class")
{
    Circle c1 = Circle(30, 20, 20, "red", "blue");
    REQUIRE(c1.get_radius() == 30);
    c1.set_radius(60);
    REQUIRE(c1.get_radius() == 60);
    REQUIRE_THROWS_AS(c1.set_fill_color("purple"), InvalidColorException);
}