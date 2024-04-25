#ifndef LORRY_H
#define LORRY_H

#include "Vehicle.hpp"

class Lorry : public Vehicle
{

public:
    // CONSTRUCTOR
    Lorry(
        std::string chassi,
        std::string model,
        uint16_t year,
        double max_load_weight,
        double max_load_volume,
        std::array<double, 2> coordinates,
        bool active);

    void honk();

    // DECONSTRUCTOR
    ~Lorry();
};

#endif