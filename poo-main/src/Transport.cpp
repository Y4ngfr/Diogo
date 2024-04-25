#include <Transport.hpp>

uint32_t Transport::new_id = 0;

//******************************************************************//
//************************ CONSTRUCTOR *****************************//
//******************************************************************//

Transport::Transport(
    uint32_t order_id,
    uint32_t vehicle_id,
    std::string collection_address,
    std::string delivery_address)
{
    /*
    Description: Constructor for Transport class.

    Parameters:
    - order_id (uint32_t): The ID of the order associated with the transport.
    - vehicle_id (uint32_t): The ID of the vehicle associated with the transport.
    - collection_address (std::string): The collection address for the transport.
    - delivery_address (std::string): The delivery address for the transport.
    */

    this->id = new_id++;
    this->order_id = order_id;
    this->vehicle_id = vehicle_id;
    this->collection_address = collection_address;
    this->delivery_address = delivery_address;
}

//******************************************************************//
//************************ SETTER FUNCTIONS ************************//
//******************************************************************//

int Transport::set_receiver_name(std::string new_receiver_name)
{
    /*
    Description: Sets the receiver's name for the transport.

    Parameters:
    - new_receiver_name (std::string): The new receiver's name.

    Returns:
    - int: 1 if the receiver's name was successfully set, 0 otherwise.
    */

    this->receiver_name = new_receiver_name;
    return 1;
}

//******************************************************************//
//************************* GETTER FUNCTIONS ***********************//
//******************************************************************//

uint32_t Transport::get_id()
{
    /*
    Description: Gets the ID of the transport.

    Returns:
    - uint32_t: The ID of the transport.
    */

    return this->id;
}

uint32_t Transport::get_order_id()
{
    /*
    Description: Gets the ID of the order associated with the transport.

    Returns:
    - uint32_t: The ID of the order.
    */

    return this->order_id;
}

uint32_t Transport::get_vehicle_id()
{
    /*
    Description: Gets the ID of the vehicle associated with the transport.

    Returns:
    - uint32_t: The ID of the vehicle.
    */

    return this->vehicle_id;
}

std::string Transport::get_collection_address()
{
    /*
    Description: Gets the collection address of the transport.

    Returns:
    - std::string: The collection address of the transport.
    */

    return this->collection_address;
}

std::string Transport::get_delivery_address()
{
    /*
    Description: Gets the delivery address of the transport.

    Returns:
    - std::string: The delivery address of the transport.
    */

    return this->delivery_address;
}

std::string Transport::get_receiver_name()
{
    /*
    Description: Gets the receiver's name of the transport.

    Returns:
    - std::string: The receiver's name of the transport.
    */

    return this->receiver_name;
}

//******************************************************************//
//*********************** OPERATOR OVERLOADING *********************//
//******************************************************************//

std::ostream &operator<<(std::ostream &os, const Transport *transport)
{
    os << "------------------ Transport -------------------"
       << "\n";
    os << "ID: " << transport->id << "\n";
    os << "Order ID: " << transport->order_id << "\n";
    os << "Vehicle ID: " << transport->vehicle_id << "\n";
    os << "Collection Address: " << transport->collection_address << "\n";
    os << "Delivery Address: " << transport->delivery_address << "\n";
    os << "Receiver Name: " << transport->receiver_name << "\n";
    os << "------------------------------------------------"
       << "\n\n";

    return os;
}

bool Transport::operator==(Transport &other)
{
    return this->id == other.id;
}