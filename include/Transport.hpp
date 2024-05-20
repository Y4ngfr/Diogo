#ifndef TRANSPORT_HPP
#define TRANSPORT_HPP

#include <iostream>
#include <string>
#include <array>

class Transport {
private:
    static uint32_t new_id;
    uint32_t id;
    uint32_t order_id;
    uint32_t vehicle_id;
    std::array<double, 2> collection_address;
    std::array<double, 2> delivery_address;
    std::string receiver_name = "";

public:
    Transport(
        uint32_t order_id,
        uint32_t vehicle_id,
        std::array<double, 2> collection_address,
        std::array<double, 2> delivery_address
    );

    // Setter methods
    int set_receiver_name(std::string new_receiver_name);

    // Getter methods
    uint32_t get_id();
    uint32_t get_order_id();
    uint32_t get_vehicle_id();
    std::array<double, 2> get_collection_address();
    std::array<double, 2> get_delivery_address();
    std::string get_receiver_name();

    friend std::ostream& operator<<(std::ostream& os, const Transport* transport);
    bool operator==(Transport& other);
};

#endif