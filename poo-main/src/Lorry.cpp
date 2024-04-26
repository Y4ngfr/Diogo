#include <iostream>
#include "../include/Lorry.hpp"

Lorry::Lorry(
    std::string chassi,
    std::string model,
    uint16_t year,
    double max_load_weight,
    double max_load_volume,
    std::array<double, 2> coordinates,
    bool active = 0) : Vehicle(chassi, model, year, "lorry", max_load_weight, max_load_volume, coordinates, active) {}

void Lorry::honk()
{
    std::cout << "honk-honk ";
}

Lorry::~Lorry()
{
    // Nothing to do
}