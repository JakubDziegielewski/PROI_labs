#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <stdexcept>
#include "item.hpp"

TEST_CASE("Test primary item operations")
{
    Item orange = Item("Orange", 8.0000, "Fruits");
    Item apple = Item("Apple", 6.0000, "Fruit");
    Item other_orange = Item("Orange", 8.0000, "Fruits");

    REQUIRE(orange.is_item_from_producer("Orange", "Fruits"));
    REQUIRE_FALSE(orange.is_item_from_producer("Orange", "Vegetables"));
    REQUIRE_FALSE(orange.is_item_from_producer("Apple", "Fruits"));
    REQUIRE_FALSE(orange.is_item_from_producer("Apple", "Vegetables"));
    REQUIRE(orange == other_orange);
    REQUIRE_FALSE(orange == apple);
    REQUIRE_THROWS_AS(orange.set_price(-1.23000), std::invalid_argument);
    REQUIRE_THROWS_AS(Item("Grape", -22.22000, "Fruit"), std::invalid_argument);
}
