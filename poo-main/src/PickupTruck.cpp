#include <PickupTruck.hpp>

PickupTruck::PickupTruck(
    std::string chassi,
    std::string model,
    uint16_t year,
    double max_load_weight,
    double max_load_volume,
    std::array<double, 2> coordinates,
    bool active = 0) : Vehicle(chassi, model, year, "pickup truck", max_load_weight, max_load_volume, coordinates, active) {}

void PickupTruck::honk()
{
    std::cout << "honk ";
}

PickupTruck::~PickupTruck()
{
    // Nothing to do
}