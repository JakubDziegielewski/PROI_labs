#pragma once
#include <string>
#include <vector>
#include <iostream>

class Company
{
private:
    std::string name;
    std::string tin;

public:
    Company(const std::string name, const std::string tin);
    std::string get_name() const;
    std::string get_tin() const;
    void set_name(const std::string name);
    friend std::ostream &operator<<(std::ostream &os, const Company &company);
};

std::ostream &operator<<(std::ostream &os, const Company &company);