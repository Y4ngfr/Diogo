#ifndef PICKUPTRUCK_H
#define PICKUPTRUCK_H

#include "Vehicle.hpp"

class PickupTruck : public Vehicle
{

public:
    // CONSTRUCTOR
    PickupTruck(
        std::string chassi,
        std::string model,
        uint16_t year,
        double max_load_weight,
        double max_load_volume,
        std::array<double, 2> coordinates,
        bool active);

    void honk();

    // DECONSTRUCTOR
    ~PickupTruck();
};

#endif