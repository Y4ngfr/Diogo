#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <array>

class Order{
private:
    static uint32_t new_id;
    uint32_t id;
    uint32_t client_id;
    uint32_t transport_id;
    std::string description;
    std::string type_of_transportation;
    std::array<double, 2> collection_address;
    std::array<double, 2> delivery_address;
    double load_weight; // In Kg
    double load_volume; // In Liters

public:
    // CONSTRUCTOR
    Order(
        uint32_t client_id,
        std::string description,
        std::string type_of_transportation,
        std::array<double, 2> collection_address,
        std::array<double, 2> delivery_address,
        double load_weight,
        double load_volume
    );

    // GETTER FUNCTIONS
    uint32_t get_id();
    uint32_t get_client_id();
    uint32_t get_transport_id();
    std::string get_description();
    std::string get_type_of_transportation();
    std::array<double, 2> get_collection_address();
    std::array<double, 2> get_delivery_address();
    double get_load_weight();
    double get_load_volume();

    // OPERATOR FUNCTIONS
    friend std::ostream& operator<<(std::ostream& os, const Order* ord);
    bool operator==(Order &other);

    // DECONSTRUCTOR
    ~Order();
};

#endif