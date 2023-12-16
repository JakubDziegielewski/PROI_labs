#pragma once
#include "order.hpp"
#include "company.hpp"
#include <iostream>
#include <optional>
#include <vector>

class Invoice
{
private:
    Company issuer;
    Company recipient;
    std::vector<Order> orders;
    long double sum;
    void calculate_sum();
    std::vector<Order>::iterator find_order(const Order &order);

public:
    Invoice(const Company issuer, const Company recipient);
    Invoice() = default;
    Company get_issuer() const;
    Company get_recipient() const;
    std::vector<Order> get_orders() const;
    void set_issuer(Company issuer);
    void set_recipient(Company recipient);
    std::optional<Order> find_order(std::string name, std::string producer);
    bool add_order(const Order &order);
    bool edit_order(const Order &old_order, const Order &new_order);
    bool edit_order(std::string old_name, std::string old_producer, const Order &new_order);
    void delete_order(const Order &order);
    void delete_order(std::string item, std::string producer);
    void sort_orders_by_total_price();
    void sort_orders_by_item();
    friend std::ostream &operator<<(std::ostream &os, const Invoice &invoice);
};
std::ostream &operator<<(std::ostream &os, const Invoice &invoice);