#include <iostream>
#include <cmath> 
#include "../include/TransportManager.hpp"
#include "../include/GeoShell.hpp"

//******************************************************************//
//*************************** CONSTRUCTOR **************************//
//******************************************************************//

TransportManager::TransportManager(Garage *garage)
{
    /*
        Description: TransportManager's constructor.

        Parameters:
        - garage (Garage*): Garage containing the available vehicles.
    */
    this->garage = garage;
}

//******************************************************************//
//*********************** MANAGING FUNCTIONS ***********************//
//******************************************************************//

uint32_t TransportManager::new_transport(Order *order, bool new_vehicle)
{
    /*
        Description: Creates a new transport for the given order.

        Parameters:
        - order (Order*): Order for which the transport is created.
        - new_vehicle (bool): Flag indicating if a new vehicle should be allocated for the transport.

        Returns:
        - uint32_t: ID of the newly created transport.
    */

    // Finding closest available vehicle for the order
    Vehicle *vehicle = find_closest_available_vehicle(order);

    // Checking if no vehicle was found
    if (vehicle == NULL)
        throw std::runtime_error("No such available vehicle in garage");

    // Creating a transport based on given variables
    Transport *new_transport = new Transport(order->get_id(), vehicle->get_id(), order->get_collection_address(), order->get_delivery_address());

    // Adding transport to transports list
    this->transports.push_back(new_transport);

    // Changing vehicle capacities
    vehicle->change_load_weight(order->get_load_weight() * -1);
    vehicle->change_load_volume(order->get_load_volume() * -1);

    return new_transport->get_id();
}

int TransportManager::close_transport(Order *order, std::string receiver_name)
{
    /*
        Description: Closes the transport for the given order by setting the receiver's name.

        Parameters:
        - transport_id (uint32_t): ID of the transport to close.
        - receiver_name (std::string): Name of the receiver.

        Returns:
        - int: 1 if the transport was successfully closed, 0 otherwise.
    */
    for (Transport *transport : this->transports)
    {
        if (transport->get_order_id() == order->get_id())
        {
            if (transport->get_receiver_name() == "")
            {
                transport->set_receiver_name(receiver_name);
                this->garage->get_vehicle(transport->get_vehicle_id())->change_load_weight(order->get_load_weight());
                this->garage->get_vehicle(transport->get_vehicle_id())->change_load_volume(order->get_load_volume());
                return 1;
            }
        }
    }
    return 0;
}

//******************************************************************//
//************************ HELPER FUNCTIONS ************************//
//******************************************************************//

Vehicle *TransportManager::find_closest_available_vehicle(Order *order)
{
    /*
        Description: Finds the closest available vehicle to the given address.

        Parameters:
        - order (Order*): Contains the address and the physical proprieties of the order.

        Returns:
        - Vehicle*: Pointer to the closest available vehicle, or NULL if no vehicle is available.
    */
    double closest_distance = MAXFLOAT;
    Vehicle *closest_vehicle = NULL;

    for (Vehicle *vehicle : this->garage->get_vehicles_list())
    {
        double distance = calculate_distance(vehicle->get_coordinates(), GeoShell::get_coordinates(order->get_collection_address()));

        // Checking if vehicle is further away
        if (distance > closest_distance)
            continue;

        // Checking if vehicle type is different from demanded
        if (vehicle->get_type() != order->get_type_of_transportation())
            continue;

        // Checking if vehicle doesn't has enough capacity
        if ((vehicle->get_max_load_volume() < order->get_load_volume()) || (vehicle->get_max_load_weight() < order->get_load_weight()))
            continue;

        closest_distance = distance;
        closest_vehicle = vehicle;
    }

    return closest_vehicle;
}

double TransportManager::calculate_distance(std::array<double, 2> coordinates1, std::array<double, 2> coordinates2)
{
    /*
        Description: Calculates the distance between two sets of coordinates.

        Parameters:
        - coordinates1 (std::array<double, 2>): Coordinates of the first point.
        - coordinates2 (std::array<double, 2>): Coordinates of the second point.

        Returns:
        - double: Distance between the two points.
    */
    double distance_x = std::pow(coordinates1[0] - coordinates2[0], 2);
    double distance_y = std::pow(coordinates1[1] - coordinates2[1], 2);

    // Computing distance based in Pythagoras theorem
    double distance = std::sqrt(distance_x + distance_y);

    return distance;
}

//******************************************************************//
//************************ LISTER FUNCTIONS ************************//
//******************************************************************//

std::vector<Transport *> TransportManager::list_transports_by_order_id(int32_t order_id)
{
    /*
        Description: Lists the transports associated with the given order ID.

        Parameters:
        - order_id (int32_t): ID of the order.

        Returns:
        - std::vector<Transport*>: Vector of transports associated with the order ID.
    */
    std::vector<Transport *> transports;
    for (Transport *transport : this->transports)
    {
        if (transport->get_order_id() == order_id)
        {
            transports.push_back(transport);
        }
    }
    return transports;
}

std::vector<Transport *> TransportManager::list_pending_transports_by_vehicle_id(int32_t vehicle_id)
{
    /*
        Description: Lists the pending transports associated with the given vehicle ID.

        Parameters:
        - vehicle_id (int32_t): ID of the vehicle.

        Returns:
        - std::vector<Transport*>: Vector of pending transports associated with the vehicle ID.
    */
    std::vector<Transport *> transports;
    for (Transport *transport : this->transports)
    {
        if (transport->get_vehicle_id() == vehicle_id)
        {
            if (transport->get_receiver_name() != "")
            {
                continue;
            }
            transports.push_back(transport);
        }
    }
    return transports;
}

std::vector<Transport *> TransportManager::list_pending_transports_by_order_id(int32_t order_id)
{
    /*
        Description: Lists the pending transports associated with the given order ID.

        Parameters:
        - order_id (int32_t): ID of the order.

        Returns:
        - std::vector<Transport*>: Vector of pending transports associated with the order ID.
    */
    std::vector<Transport *> transports;
    for (Transport *transport : this->transports)
    {
        if (transport->get_order_id() == order_id)
        {
            if (transport->get_receiver_name() != "")
            {
                continue;
            }
            transports.push_back(transport);
        }
    }
    return transports;
}

std::vector<Transport *> TransportManager::list_transports_by_vehicle_id(int32_t vehicle_id)
{
    /*
        Description: Lists the transports associated with the given vehicle ID.

        Parameters:
        - vehicle_id (int32_t): ID of the vehicle.

        Returns:
        - std::vector<Transport*>: Vector of transports associated with the vehicle ID.
    */
    std::vector<Transport *> transports;
    for (Transport *transport : this->transports)
    {
        if (transport->get_vehicle_id() == vehicle_id)
        {
            transports.push_back(transport);
        }
    }
    return transports;
}

//******************************************************************//
//*********************** PRINTER FUNCTIONS ************************//
//******************************************************************//

void TransportManager::print_pending_transports(uint32_t vehicle_id)
{
    /*
        Description: Prints the IDs of pending transports associated with the given vehicle ID.

        Parameters:
        - vehicle_id (uint32_t): ID of the vehicle.
    */
    std::cout << "Listing pending transport of vehicle " << vehicle_id << ": ";
    for (Transport *transport : this->list_pending_transports_by_vehicle_id(vehicle_id))
    {
        std::cout << transport->get_id() << " ";
    }
    std::cout << std::endl;
}