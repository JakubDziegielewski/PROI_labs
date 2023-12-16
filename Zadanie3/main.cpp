#include "party.hpp"
#include <iostream>

int main()
{
    Party party = Party();
    party.add_guest(Person("Adam", "Maj"));
    party.add_guest(Person("Bob", "Kwiecen"));
    party.add_guest(Person("Anna", "Grudzien"));

    std::cout << party << std::endl;
    ;

    party.sort_by_surname();

    std::cout << party;

    std::optional<Person> guest = party.find_guest("Adam", "Maj");

    if (guest)
    {
        std::cout << guest.value();
    }
    else{
        std::cout << "Guest does not exist\n";
    }

    party.remove_guest(Person("Adam", "Maj"));

    guest = party.find_guest("Adam", "Maj");
    if (guest)
    {
        std::cout << guest.value();
    }
     else{
        std::cout << "Guest does not exist\n";
    }
}