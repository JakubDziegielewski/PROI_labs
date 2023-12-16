#pragma once
#include <string>

class Person
{
private:
    std::string name;
    std::string surname;

public:
    Person(std::string name, std::string surname);
    Person();
    std::string get_name() const;
    std::string get_surname() const;
    void set_name(std::string name);
    void set_surname(std::string surname);
    bool has_given_name(std::string name, std::string surname) const;
    bool operator==(const Person &person) const;
    bool operator<(const Person &person) const;
    friend std::ostream &operator<<(std::ostream &os, const Person &person);
};

std::ostream &operator<<(std::ostream &os, const Person &person);