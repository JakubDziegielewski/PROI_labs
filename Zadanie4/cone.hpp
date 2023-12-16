#pragma once
#include "solid_of_revolution.hpp"

class Cone : public SolidOfRevolution{
        public:
    Cone(size_t base_radius, size_t height);
    ~Cone() = default;
    double calculate_volume() const;
};