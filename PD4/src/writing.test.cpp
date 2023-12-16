#define CATCH_CONFIG_MAIN
#include "writing.hpp"
#include "invalid_color_exception.hpp"
#include <catch2/catch.hpp>

TEST_CASE("Testing Writing class")
{
    Writing w1 = Writing("Test", 12, "middle", 33, 36, "blue", "blue");
    REQUIRE(w1.get_text_anchor() == "middle");
    REQUIRE(w1.get_stroke_color() == "blue");
    w1.set_text("test_too");
    REQUIRE(w1.get_text() == "test_too");
    REQUIRE_THROWS_AS(w1.set_fill_color("brown"), InvalidColorException);
}