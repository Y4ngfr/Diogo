#include <Vehicle.hpp>
#include <GeoShell.hpp>
#include <array>

uint32_t Vehicle::new_id = 0;

//******************************************************************//
//*************************** CONSTRUCTOR **************************//
//******************************************************************//

Vehicle::Vehicle(
    std::string chassi,
    std::string model,
    uint16_t year,
    std::string type,
    double max_load_weight,
    double max_load_volume,
    std::array<double, 2> coordinates,
    bool active = 0)
{
    /*
    Description: Constructor for Vehicle class.

    Parameters:
    - chassi (std::string): The chassis number of the vehicle.
    - model (std::string): The model of the vehicle.
    - year (uint16_t): The year of manufacture of the vehicle.
    - type (std::string): The type of the vehicle (e.g., car, lorry, pickup truck).
    - max_load_weight (double): The maximum load weight the vehicle can carry.
    - max_load_volume (double): The maximum load volume the vehicle can carry.
    - coordinates (std::array<double, 2>): The current coordinates of the vehicle (latitude and longitude).
    - active (bool): Flag indicating if the vehicle is active (default is false).
    */

    // Checking if load weight have a invalid value
    if (max_load_weight < 0)
        throw std::invalid_argument("Max load weight cannot be negative");

    // Checking if load volume have a invalid value
    if (max_load_volume < 0)
        throw std::invalid_argument("Max load volume cannot be negative");

    // Setting attributes
    this->id = new_id++;
    this->chassi = chassi;
    this->model = model;
    this->year = year;
    this->type = type;
    this->max_load_volume = max_load_volume;
    this->max_load_weight = max_load_weight;
    this->set_coordinates(coordinates);
    this->active;
}

//******************************************************************//
//************************* SETTER FUNCTIONS ***********************//
//******************************************************************//

int Vehicle::set_active(bool new_active)
{
    /*
    Description: Sets the active status of the vehicle.

    Parameters:
    - new_active (bool): The new active status for the vehicle.

    Returns:
    - int: 1 if the operation is successful, 0 otherwise.
    */

    this->active = new_active;
    return 1;
}

int Vehicle::set_coordinates(std::string new_location) // TBD
{
    /*
    Description: Sets the coordinates of the vehicle based on a string location.

    Parameters:
    - new_location (std::string): The new location for the vehicle.

    Returns:
    - int: 1 if the operation is successful, 0 otherwise.
    */

    this->coordinates = GeoShell::get_coordinates(new_location);
    return 1;
}

int Vehicle::set_coordinates(std::array<double, 2> new_coordinates)
{
    /*
    Description: Sets the coordinates of the vehicle based on an array of doubles.

    Parameters:
    - new_coordinates (std::array<double, 2>): The new coordinates for the vehicle.

    Returns:
    - int: 1 if the operation is successful, 0 otherwise.
    */

    this->coordinates = new_coordinates;
    return 1;
}

//******************************************************************//
//************************* GETTER FUNCTIONS ***********************//
//******************************************************************//

uint32_t Vehicle::get_id()
{
    /*
    Description: Gets the ID of the vehicle.

    Returns:
    - uint32_t: The ID of the vehicle.
    */

    return this->id;
}

std::string Vehicle::get_chassi()
{
    /*
    Description: Gets the chassis number of the vehicle.

    Returns:
    - std::string: The chassis number of the vehicle.
    */

    return this->chassi;
}

std::string Vehicle::get_model()
{
    /*
    Description: Gets the model of the vehicle.

    Returns:
    - std::string: The model of the vehicle.
    */

    return this->model;
}

uint16_t Vehicle::get_year()
{
    /*
    Description: Gets the year of manufacture of the vehicle.

    Returns:
    - uint16_t: The year of manufacture of the vehicle.
    */

    return this->year;
}

bool Vehicle::get_active()
{
    /*
    Description: Gets the active status of the vehicle.

    Returns:
    - bool: The active status of the vehicle.
    */

    return this->active;
}

double Vehicle::get_max_load_volume()
{
    /*
    Description: Gets the maximum load volume the vehicle can carry.

    Returns:
    - double: The maximum load volume of the vehicle.
    */

    return this->max_load_volume;
}

double Vehicle::get_max_load_weight()
{
    /*
    Description: Gets the maximum load weight the vehicle can carry.

    Returns:
    - double: The maximum load weight of the vehicle.
    */

    return this->max_load_weight;
}

std::array<double, 2> Vehicle::get_coordinates()
{
    /*
    Description: Gets the current coordinates of the vehicle.

    Returns:
    - std::array<double, 2>: The current coordinates of the vehicle (latitude and longitude).
    */

    return this->coordinates;
}

std::string Vehicle::get_type()
{
    /*
    Description: Gets the type of the vehicle.

    Returns:
    - std::string: The type of the vehicle.
    */

    return this->type;
}

//******************************************************************//
//********************** LOAD CAPACITY FUNCTIONS *******************//
//******************************************************************//

int Vehicle::change_load_volume(double load)
{
    /*
    Description: Changes the load volume of the vehicle by the specified amount.

    Parameters:
    - load (double): The amount by which to change the load volume.

    Returns:
    - int: 1 if the operation is successful, 0 otherwise.
    */

    this->max_load_volume += load;
    return 1;
}

int Vehicle::change_load_weight(double load)
{
    /*
    Description: Changes the load weight of the vehicle by the specified amount.

    Parameters:
    - load (double): The amount by which to change the load weight.

    Returns:
    - int: 1 if the operation is successful, 0 otherwise.
    */

    this->max_load_weight += load;
    return 1;
}

//******************************************************************//
//*********************** OPERATOR OVERLOADING *********************//
//******************************************************************//

std::ostream &operator<<(std::ostream &os, const Vehicle *vehicle)
{
    os << "-------------------- Vehicle -------------------"
       << "\n";
    os << "ID: " << vehicle->id << "\n";
    os << "Chassi: " << vehicle->chassi << "\n";
    os << "Model: " << vehicle->model << "\n";
    os << "Year: " << vehicle->year << "\n";
    os << "Active: " << vehicle->active << "\n";
    os << "Coordinates: " << vehicle->coordinates[0] << " " << vehicle->coordinates[1] << "\n";
    os << "------------------------------------------------"
       << "\n\n";

    return os;
}

bool Vehicle::operator==(Vehicle &other)
{
    return this->id == other.id;
}

//******************************************************************//
//************************** DECONSTRUCTOR *************************//
//******************************************************************//

Vehicle::~Vehicle()
{
    // Nothing to do
}