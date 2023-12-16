#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "party.hpp"
#include <stdexcept>
#include <vector>

TEST_CASE("Test primary operations"){
    Party party = Party();
    party.add_guest(Person("Adam", "Maj"));
    party.add_guest(Person("Bob", "Kwiecen"));
    party.add_guest(Person("Anna", "Grudzien"));

    REQUIRE(party.find_guest("Adam", "Maj"));
    party.sort_by_surname();
    std::vector<Person> guests = party.get_guests();
    REQUIRE(guests[1] == Person("Bob", "Kwiecien"));
    REQUIRE(guests[0] == Person("Anna", "Grudzien"));
    party.remove_guest(Person("Adam", "Maj"));
    REQUIRE_FALSE(party.find_guest("Adam", "Maj"));
}