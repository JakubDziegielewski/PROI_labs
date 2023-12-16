#define CATCH_CONFIG_MAIN
#include "rectangle.hpp"
#include "invalid_color_exception.hpp"
#include <catch2/catch.hpp>

TEST_CASE("Testing Rectangle class")
{
    Rectangle r1 = Rectangle(10, 10, 30, 30, "black", "red");
    REQUIRE(r1.get_x() == 30);
    REQUIRE(r1.get_width() == 10);
    REQUIRE(r1.get_stroke_color() == "black");
    REQUIRE(r1.get_fill_color() == "red");
    r1.set_height(50);
    REQUIRE(r1.get_height() == 50);
    REQUIRE_THROWS_AS(r1.set_stroke_color("orange"), InvalidColorException);
}