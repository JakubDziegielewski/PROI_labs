#include "cone.hpp"

Cone::Cone(size_t base_radius, size_t height) : SolidOfRevolution(base_radius, height){

}

double Cone::calculate_volume() const{
    return this->base.calculate_area() * this->height / 3;
}