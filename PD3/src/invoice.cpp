#include "invoice.hpp"
#include <vector>
#include <algorithm>

Invoice::Invoice(const Company issuer, const Company recipient) : issuer(issuer), recipient(recipient)
{
    orders = std::vector<Order>{};
}

void Invoice::calculate_sum()
{
    long double sum = 0;
    for (auto order : orders)
    {
        sum += order.get_full_price();
    }
    this->sum = sum;
}

Company Invoice::get_issuer() const
{
    return issuer;
}
Company Invoice::get_recipient() const
{
    return recipient;
}

std::vector<Order> Invoice::get_orders() const
{
    return orders;
}

void Invoice::set_issuer(Company issuer)
{
    this->issuer = issuer;
}

void Invoice::set_recipient(Company issuer)
{
    this->recipient = recipient;
}

std::vector<Order>::iterator Invoice::find_order(const Order &order)
{
    auto found_order = std::find(orders.begin(), orders.end(), order);

    return found_order;
}

std::optional<Order> Invoice::find_order(std::string name, std::string producer)
{
    auto found_order = std::find_if(orders.begin(), orders.end(),
                                    [&](const Order &o)
                                    { return o.get_item().is_item_from_producer(name, producer); });
    if (found_order != orders.end())
    {
        return std::optional<Order>(*found_order);
    }
    return std::nullopt;
}

bool Invoice::add_order(const Order &order)
{
    if (find_order(order) == orders.end())
    {
        orders.push_back(order);
        calculate_sum();
        return true;
    }
    return false;
}

bool Invoice::edit_order(const Order &old_order, const Order &new_order)
{
    if (find_order(new_order) == orders.end())
    {
        std::replace(orders.begin(), orders.end(), old_order, new_order);
        calculate_sum();
        return true;
    }
    return false;
}

bool Invoice::edit_order(std::string old_name, std::string old_producer, const Order &new_order)
{
    if (find_order(new_order) == orders.end())
    {
        std::replace_if(
            orders.begin(), orders.end(),
            [&](const Order &o)
            { return o.get_item().is_item_from_producer(old_name, old_producer); },
            new_order);
        calculate_sum();
        return true;
    }
    return false;
}

void Invoice::delete_order(const Order &order)
{
    auto logical_end = std::remove(orders.begin(), orders.end(), order);
    orders.erase(logical_end, orders.end());
    calculate_sum();
}

void Invoice::delete_order(std::string item, std::string producer)
{
    orders.erase(std::remove_if(orders.begin(), orders.end(),
                                [&](const Order &o)
                                { return o.get_item().is_item_from_producer(item, producer); }),
                 orders.end());
    calculate_sum();
}

void Invoice::sort_orders_by_total_price()
{
    std::sort(orders.begin(), orders.end());
}

void Invoice::sort_orders_by_item()
{
    std::sort(orders.begin(), orders.end(), [](const Order &first, const Order &second)
              { return first.get_item().get_name() < second.get_item().get_name(); });
}

std::ostream &operator<<(std::ostream &os, const Invoice &invoice)
{

    os << "INVOICE\n"
       << "Issuer: " << invoice.issuer
       << "Recipient: " << invoice.recipient
       << "Sum: " << invoice.sum << std::endl
       << "Orders:\n";
    unsigned counter = 1;
    for (auto &order : invoice.orders)
    {
        os << counter << ". " << std::endl
           << order << std::endl;
        counter++;
    }
    return os;
}