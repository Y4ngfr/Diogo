#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <array>

class Vehicle{
protected:
    static uint32_t new_id;
    std::string type;
    uint32_t id;
    std::string chassi;
    std::string model;
    uint16_t year;
    bool active;
    double max_load_weight;
    double max_load_volume;
    std::array<double, 2> coordinates;

public:
    // CONSTRUCTOR
    Vehicle(
        std::string chassi,
        std::string model,
        uint16_t year,
        std::string type,
        double max_load_weight,
        double max_load_volume,
        std::array<double, 2> coordinates,
        bool active
    );

    // VIRTUAL METHOD
    virtual void honk() = 0;

    // SETTER FUNCTIONS
    int set_active(bool new_active);
    int set_max_load_weight(double new_max_load_weight);
    int set_max_load_volume(double new_max_load_volume);
    int set_coordinates(std::string new_location);
    int set_coordinates(std::array<double, 2> new_coordinates);

    // GETTER FUNCTIONS
    uint32_t get_id();
    std::string get_chassi();
    std::string get_model();
    uint16_t get_year();
    std::string get_type();
    bool get_active();
    double get_max_load_volume();
    double get_max_load_weight();
    std::array<double, 2> get_coordinates();
    int change_load_volume(double load);
    int change_load_weight(double load);

    // OPERATOR FUNCTIONS
    friend std::ostream& operator<<(std::ostream& os, const Vehicle* vehicle);
    bool operator==(Vehicle& other);

    // DECONSTRUCTOR
    ~Vehicle();
};

#endif