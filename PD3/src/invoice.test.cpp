#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <stdexcept>
#include "invoice.hpp"
#include "company.hpp"
#include "item.hpp"
#include "order.hpp"

TEST_CASE("Invoice testing")
{
    Company one = Company("One", "PL1234567895");
    Company two = Company("Two", "PL1234567896");
    Item orange = Item("orange", 9.00000, "Fruit");
    Item apple = Item("apple", 8.00000, "Fruit");
    Item pear = Item("pear", 6.00000, "Fruit");
    Order order_one = Order(1, orange, 10);
    Order order_two = Order(2, apple, 4);
    Order order_three = Order(3, pear, 2);

    SECTION("Adding, editing and deleting orders")
    {

        Invoice invoice_one = Invoice(one, two);
        REQUIRE(invoice_one.add_order(order_one));
        REQUIRE(invoice_one.add_order(order_two));
        REQUIRE_FALSE(invoice_one.add_order(order_one));
        REQUIRE(invoice_one.edit_order(order_one, order_three));
        REQUIRE(invoice_one.add_order(order_one));
        REQUIRE_FALSE(invoice_one.edit_order(order_one, order_two));
        REQUIRE(invoice_one.find_order("orange", "Fruit"));
        invoice_one.delete_order(order_one);
        REQUIRE_FALSE(invoice_one.find_order("orange", "Fruit"));
        Invoice invoice_two = Invoice(one, two);
        invoice_two.add_order(order_one);
    }

    SECTION("Testing sorting methods")
    {
        Invoice invoice_one = Invoice(one, two);
        invoice_one.add_order(order_one);
        invoice_one.add_order(order_two);
        invoice_one.add_order(order_three);
        invoice_one.sort_orders_by_item();
        REQUIRE(invoice_one.get_orders()[0] == order_two);
        invoice_one.sort_orders_by_total_price();
        REQUIRE(invoice_one.get_orders()[0] == order_three);
    }
}
