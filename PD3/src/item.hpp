#pragma once
#include <string>
#include <iostream>
class Item
{
private:
    std::string name;
    long double price;
    std::string producer;

public:
    Item(const std::string name, long double price, const std::string producer);
    Item() = default;
    std::string get_name() const;
    long double get_price() const;
    std::string get_producer() const;
    void set_name(std::string name);
    void set_price(long double price);
    void set_producer(std::string producer);
    bool is_item_from_producer(std::string name, std::string producer);
    bool operator==(const Item &item) const;
    friend std::ostream &operator<<(std::ostream &os, const Item &item);
};

std::ostream &operator<<(std::ostream &os, const Item &item);
