#include "party.hpp"
#include <algorithm>
#include <iostream>

std::vector<Person>::iterator Party::find_guest(const Person &person){
 auto guest = std::find(guests.begin(), guests.end(), person);

 return guest;
}

std::optional<Person> Party::find_guest(std::string first_name, std::string last_name) const
{
    auto guest_it = std::find_if(guests.begin(), guests.end(), 
                        [&](const Person& p){ return p.has_given_name(first_name, last_name); });
    if (guest_it != guests.end())
    {
       return std::optional<Person>(*guest_it);
    }
    
    return std::nullopt;
   
}
bool Party::add_guest(const Person& person){
    if (find_guest(person) == guests.end())
    {
        guests.push_back(person);
        return true;
    }
    return false;
}

void Party::remove_guest(const Person& person){
    auto logical_end = std::remove(guests.begin(), guests.end(), person);
    guests.erase(logical_end, guests.end());
}

void Party::sort_by_surname(){
    std::sort(guests.begin(), guests.end());
}

 std::vector<Person> Party::get_guests() const{
    return guests;
 }

std::ostream &operator<<(std::ostream &os, const Party &party){
    for (const auto& guest : party.guests)
    {
        os  << guest;
    }
    return os;
}