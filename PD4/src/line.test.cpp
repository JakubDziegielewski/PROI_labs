#define CATCH_CONFIG_MAIN
#include "line.hpp"
#include "invalid_color_exception.hpp"
#include <catch2/catch.hpp>

TEST_CASE("Testing Line class")
{
    Line l1 = Line(10, 10, 30, 30, "black");
    REQUIRE(l1.get_x() == 10);
    REQUIRE(l1.get_stroke_color() == "black");
    l1.set_stroke_color("blue");
    REQUIRE(l1.get_stroke_color() == "blue");
    REQUIRE_THROWS_AS(l1.set_stroke_color("orange"), InvalidColorException);
}