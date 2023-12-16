#include "order.hpp"
#include <stdexcept>

Order::Order(uint32_t id, Item item, size_t quantity) : id(id), item(item), quantity(quantity)
{
    if(quantity == 0){
        throw std::invalid_argument("Quantity must be bigger than 0");
    }
}
Order::Order()
{
}

uint32_t Order::get_id() const
{
    return id;
}

Item Order::get_item() const
{
    return item;
}

size_t Order::get_quantity() const
{
    return quantity;
}

long double Order::get_full_price() const
{
    return item.get_price() * static_cast<long double>(quantity);
}

void Order::set_id(uint32_t id)
{
    this->id = id;
}

void Order::set_item(Item item)
{
    this->item = item;
}

void Order::set_quantity(size_t quantity)
{
    if(quantity == 0){
        throw std::invalid_argument("Quantity must be bigger than 0");
    }
    this->quantity = quantity;
}

bool Order::operator==(const Order &order) const
{
    return id == order.id && item == order.item && quantity == order.quantity;
}

bool Order::operator<(const Order &order) const
{
    return get_full_price() < order.get_full_price();
}

std::ostream &operator<<(std::ostream &os, const Order &order)
{
    os << "id: " << order.id << " " << std::endl
       << "item: " << order.item
       << "quantity: " << order.quantity << std::endl
       << "full price: " << order.get_full_price() << std::endl;
    return os;
}
