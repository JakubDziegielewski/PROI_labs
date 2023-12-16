#include "company.hpp"
#include <algorithm>
#include <stdexcept>

Company::Company(const std::string name, const std::string tin) : name(name), tin(tin)
{
}
std::string Company::get_name() const
{
    return name;
}
std::string Company::get_tin() const
{
    return tin;
}

void Company::set_name(std::string name)
{
    this->name = name;
}

std::ostream &operator<<(std::ostream &os, const Company &company)
{
    os << "Company name: " << company.name << " " << std::endl
       << "TIN: " << company.tin << std::endl;
    return os;
}