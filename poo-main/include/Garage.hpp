#ifndef GARAGE_H
#define GARAGE_H

#include <vector>
#include "Vehicle.hpp"

class Garage
{
private:
    std::vector<Vehicle *> vehicles_list;

public:
    // CONSTRUCTOR
    Garage();

    // MANAGING FUNCTIONS
    int add_vehicle(
        std::string chassi,
        std::string model,
        uint16_t year,
        double max_load_weight,
        double max_load_volume,
        std::array<double, 2> coordinates,
        std::string type,
        bool active);
    int remove_vehicle(uint32_t id);
    int64_t search_vehicle(std::vector<Vehicle *> list, int first_index, int last_index, int id);

    // GETTER FUNCTIONS
    std::vector<Vehicle *> get_vehicles_list();
    Vehicle *get_vehicle(uint32_t id);
    std::vector<Vehicle *> get_active_vehicles();

    // DECONSTRUCTOR
    ~Garage();
};

#endif