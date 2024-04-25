#include <Car.hpp>

Car::Car(
    std::string chassi,
    std::string model,
    uint16_t year,
    double max_load_weight,
    double max_load_volume,
    std::array<double, 2> coordinates,
    bool active = 0) : Vehicle(chassi, model, year, "car", max_load_weight, max_load_volume, coordinates, active) {}

void Car::honk()
{
    std::cout << "beep-beep ";
}

Car::~Car() {
    // Nothing to do
}