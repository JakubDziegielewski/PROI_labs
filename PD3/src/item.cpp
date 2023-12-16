#include "item.hpp"
#include <stdexcept>

Item::Item(std::string name, long double price, std::string producer) : name(name), price(price), producer(producer)
{
    if(price < 0.00){
        throw std::invalid_argument("Price cannot be negative");
    }
}

std::string Item::get_name() const
{
    return name;
}
long double Item::get_price() const
{
    return price;
}
std::string Item::get_producer() const
{
    return producer;
}
void Item::set_name(std::string name)
{
    this->name = name;
}
void Item::set_price(long double price)
{
    if(price < 0.00){
        throw std::invalid_argument("Price cannot be negative");
    }
    this->price = price;
}
void Item::set_producer(std::string)
{
    this->producer = producer;
}

bool Item::is_item_from_producer(std::string name, std::string producer)
{
    return this->name == name && this->producer == producer;
}

bool Item::operator==(const Item &item) const
{
    return price == item.price && name == item.name && producer == item.producer;
}

std::ostream &operator<<(std::ostream &os, const Item &item)
{
    os << "Item: " << item.name << " " << std::endl
       << "Price: " << item.price << std::endl
       << "Producer: " << item.producer << std::endl;
    return os;
}
