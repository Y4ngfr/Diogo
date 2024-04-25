#ifndef CAR_H
#define CAR_H

#include "Vehicle.hpp"

class Car : public Vehicle
{

public:
    // CONSTRUCTOR
    Car(
        std::string chassi,
        std::string model,
        uint16_t year,
        double max_load_weight,
        double max_load_volume,
        std::array<double, 2> coordinates,
        bool active);

    void honk();

    // DECONSTRUCTOR
    ~Car();
};

#endif