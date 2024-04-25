#ifndef TRANSPORT_MANAGER_H
#define TRANSPORT_MANAGER_H

#include "Transport.hpp"
#include "Garage.hpp"
#include "Order.hpp"
#include <vector>
#include <array>

class TransportManager
{
private:
    std::vector<Transport *> transports;
    Garage *garage;

public:
    // CONSTRUCTOR
    TransportManager(Garage *garage);

    // HELPER FUNCTIONS
    double calculate_distance(std::array<double, 2> coordinates1, std::array<double, 2> coordinates2);
    Vehicle *find_closest_available_vehicle(Order *order);

    // TRANSPORT LIST MANAGEMENT
    uint32_t new_transport(Order *order, bool new_vehicle);
    int close_transport(Order *order, std::string receiver_name);

    // OBJECT LIST METHODS
    std::vector<Transport *> list_transports_by_order_id(int32_t order_id);
    std::vector<Transport *> list_transports_by_vehicle_id(int32_t vehicle_id);
    std::vector<Transport *> list_pending_transports_by_order_id(int32_t order_id);
    std::vector<Transport *> list_pending_transports_by_vehicle_id(int32_t vehicle_id);

    // PRINTER METHODS
    void print_pending_transports(uint32_t vehicle_id);
};

#endif
