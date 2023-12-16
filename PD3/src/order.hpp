#pragma once
#include "item.hpp"

class Order
{
private:
    uint32_t id;
    Item item;
    size_t quantity;

public:
    Order(uint32_t id, Item item, size_t quantity);
    Order();
    uint32_t get_id() const;
    Item get_item() const;
    size_t get_quantity() const;
    long double get_full_price() const;
    void set_id(uint32_t id);
    void set_item(Item item);
    void set_quantity(size_t quantity);
    bool operator==(const Order &order) const;
    bool operator<(const Order &order) const;
    friend std::ostream& operator<<(std::ostream &os, const Order &order);
};

std::ostream& operator<<(std::ostream &os, const Order &order);