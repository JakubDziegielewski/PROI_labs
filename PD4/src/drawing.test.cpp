#define CATCH_CONFIG_MAIN
#include "drawing.hpp"
#include "bad_coordinates_exception.hpp"
#include <catch2/catch.hpp>

TEST_CASE("Testing Drawing class")
{
    Drawing d1 = Drawing(300, 300);
    REQUIRE(d1.get_width() == 300);
    REQUIRE_NOTHROW(d1.add_circle(30, 150, 150, "black", "black"));
    REQUIRE_NOTHROW(d1.add_rectangle(100, 100, 150, 150, "black", "None"));
    REQUIRE_THROWS_AS(d1.add_line(350, 300, 100, 120, "blue"), BadCoordinatesException);
    REQUIRE_THROWS_AS(d1.add_writing("text", 14, "left", 300, 250, "blue", "black"), BadCoordinatesException);
}