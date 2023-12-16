#include "person.hpp"
#include <iostream>

Person::Person(std::string name, std::string surname) : name(name), surname(surname)
{
}

Person::Person()
{
}

std::string Person::get_name() const
{
    return name;
}
std::string Person::get_surname() const
{
    return surname;
}

void Person::set_name(std::string name)
{
    this->name = name;
}
void Person::set_surname(std::string surname)
{
    this->surname = surname;
}

bool Person::has_given_name(std::string name, std::string surname) const
{
    return this->name == name && this->surname == surname;
}

bool Person::operator==(const Person &person) const
{
    return this->name == person.name && this->surname == surname;
}

bool Person::operator<(const Person &person) const
{
    if (this->surname == person.surname)
    {
        return this->name < person.name;
    }
    else
    {
        return this->surname < person.surname;
    }
}

std::ostream &operator<<(std::ostream &os, const Person &person)
{
    std::cout << person.name << " " << person.surname << std::endl;
    return os;
}