#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <stdexcept>
#include "order.hpp"
#include <iomanip>

TEST_CASE("Test primary order operations")
{
    Order order_orange = Order(1, Item("orange", 8.5000, "Fruits"), 7);
    Order other_order_orange = Order(1, Item("orange", 8.5000, "Fruits"), 7);
    Order next_order_orange = Order(2, Item("orange", 8.5000, "Fruits"), 7);
    Order order_apple = Order(3, Item("apple", 6.3300, "Fruits"), 9);

    REQUIRE(order_orange.get_full_price() - static_cast<long double>(59.50000) < static_cast<long double>(0.0000000001));
    REQUIRE(order_orange.get_full_price() - static_cast<long double>(59.50000) > -static_cast<long double>(0.0000000001));
    REQUIRE(order_apple.get_full_price() - static_cast<long double>(56.97000) < static_cast<long double>(0.0000000001));
    REQUIRE(order_apple.get_full_price() - static_cast<long double>(56.97000) > -static_cast<long double>(0.0000000001));
    REQUIRE_FALSE(order_orange < order_apple);
    REQUIRE(order_orange == other_order_orange);
    REQUIRE_FALSE(order_orange == order_apple);
    REQUIRE_FALSE(order_orange == next_order_orange);
    REQUIRE_THROWS_AS(order_apple.set_quantity(0), std::invalid_argument);
    REQUIRE_THROWS_AS(Order(4, Item("grape", 12.0000, "Fruits"), 0), std::invalid_argument);
}
