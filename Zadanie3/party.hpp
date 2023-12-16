#pragma once
#include <vector>
#include <optional>
#include "person.hpp"

class Party
{
private:
    std::vector<Person> guests;
    std::vector<Person>::iterator find_guest(const Person &person);

public:
    std::optional<Person> find_guest(std::string first_name, std::string last_name) const;
    bool add_guest(const Person& person);
    void remove_guest(const Person& person);
    void sort_by_surname();
    std::vector<Person> get_guests() const;
    friend std::ostream &operator<<(std::ostream &os, const Party &party);
};

std::ostream &operator<<(std::ostream &os, const Party &party);