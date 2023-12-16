#include <iostream>
#include "cylinder.hpp"
#include "cone.hpp"
#include <vector>
#include <list>
#include <memory>

#include <iostream>

int main(){

    std::list<std::unique_ptr<SolidOfRevolution>> elements;
    std::unique_ptr<Cylinder> added_cylinder = std::make_unique<Cylinder>(1, 2);
    elements.push_back(std::move(added_cylinder));
    std::unique_ptr<Cone> added_cone = std::make_unique<Cone>(1, 2);
    elements.push_back(std::move(added_cone));

    for (const auto &element_ptr : elements)
    {
        std::cout << element_ptr->calculate_volume() << std::endl;
    }


    return 0;
}