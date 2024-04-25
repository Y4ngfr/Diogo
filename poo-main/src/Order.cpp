#include <Order.hpp>

uint32_t Order::new_id = 0;

//******************************************************************//
//*************************** CONSTRUCTOR **************************//
//******************************************************************//

Order::Order(
    uint32_t client_id,
    std::string description,
    std::string type_of_transportation,
    std::string collection_address,
    std::string delivery_address,
    double load_weight,
    double load_volume)
{
    /*
    Description: Order's constructor.

    Parameters:
    - client_id (uint32_t): ID of the client associated with the order.
    - description (std::string): Description of the order.
    - type_of_transportation (std::string): Type of transportation requested in the order.
    - collection_address (std::string): Collection address of the order.
    - delivery_address (std::string): Delivery address of the order.
    - load_weight (double): Load weight of the order.
    - load_volume (double): Load volume of the order.
    */
   
    // Checking if load weight have a invalid value
    if (load_weight < 0)
        throw std::invalid_argument("Max load weight cannot be negative");

    // Checking if load volume have a invalid value
    if (load_volume < 0)
        throw std::invalid_argument("Max load volume cannot be negative");

    // Setting attributes
    this->id = new_id++;
    this->description = description;
    this->client_id = client_id;
    this->type_of_transportation = type_of_transportation;
    this->delivery_address = delivery_address;
    this->collection_address = collection_address;
    this->load_weight = load_weight;
    this->load_volume = load_volume;
}

//******************************************************************//
//************************* GETTER FUNCTIONS ***********************//
//******************************************************************//

//******************************************************************//
//************************* GETTER FUNCTIONS ***********************//
//******************************************************************//

uint32_t Order::get_id()
{
    /*
    Description: Gets the ID of the order.

    Returns:
    - uint32_t: The ID of the order.
    */

    return this->id;
}

uint32_t Order::get_client_id()
{
    /*
    Description: Gets the ID of the client associated with the order.

    Returns:
    - uint32_t: The ID of the client associated with the order.
    */

    return this->client_id;
}

uint32_t Order::get_transport_id()
{
    /*
    Description: Gets the ID of the transport associated with the order.

    Returns:
    - uint32_t: The ID of the transport associated with the order.
    */

    return this->transport_id;
}

std::string Order::get_description()
{
    /*
    Description: Gets the description of the order.

    Returns:
    - std::string: The description of the order.
    */

    return this->description;
}

std::string Order::get_type_of_transportation()
{
    /*
    Description: Gets the type of transportation requested in the order.

    Returns:
    - std::string: The type of transportation requested in the order.
    */

    return this->type_of_transportation;
}

std::string Order::get_collection_address()
{
    /*
    Description: Gets the collection address of the order.

    Returns:
    - std::string: The collection address of the order.
    */

    return this->collection_address;
}

std::string Order::get_delivery_address()
{
    /*
    Description: Gets the delivery address of the order.

    Returns:
    - std::string: The delivery address of the order.
    */

    return this->delivery_address;
}

double Order::get_load_weight()
{
    /*
    Description: Gets the load weight of the order.

    Returns:
    - double: The load weight of the order.
    */

    return this->load_weight;
}

double Order::get_load_volume()
{
    /*
    Description: Gets the load volume of the order.

    Returns:
    - double: The load volume of the order.
    */

    return this->load_volume;
}


//******************************************************************//
//*********************** OPERATOR OVERLOADING *********************//
//******************************************************************//

std::ostream &operator<<(std::ostream &os, const Order *ord)
{
    os << "--------------------- Order ---------------------"
       << "\n";
    os << "ID: " << ord->id << "\n";
    os << "Description: " << ord->description << "\n";
    os << "Transportation type: " << ord->type_of_transportation << "\n";
    os << "Load weight: " << ord->load_weight << "\n";
    os << "-------------------------------------------------"
       << "\n\n";

    return os;
}

bool Order::operator==(Order &other)
{
    return this->id == other.id;
}

//******************************************************************//
//************************** DECONSTRUCTOR *************************//
//******************************************************************//

Order::~Order()
{
    // Nothing to do
}