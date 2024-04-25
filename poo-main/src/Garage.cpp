#include <Garage.hpp>
#include <Car.hpp>
#include <Lorry.hpp>
#include <PickupTruck.hpp>

//******************************************************************//
//*************************** CONSTRUCTOR **************************//
//******************************************************************//

Garage::Garage()
{
    /*
        Description: Garage constructor.
    */
    // Nothing to do
}

//******************************************************************//
//************************ MANAGING FUNCTIONS **********************//
//******************************************************************//

int Garage::add_vehicle(
    std::string chassi,
    std::string model,
    uint16_t year,
    double max_load_weight,
    double max_load_volume,
    std::array<double, 2> coordinates,
    std::string type,
    bool active)
{
    /*
        Description: Adds a new vehicle to the garage.

        Parameters:
        - chassi (std::string): Chassi number of the vehicle.
        - model (std::string): Model of the vehicle.
        - year (uint16_t): Year of the vehicle.
        - max_load_weight (double): Maximum load weight of the vehicle.
        - max_load_volume (double): Maximum load volume of the vehicle.
        - coordinates (std::array<double, 2>): Coordinates of the vehicle.
        - type (std::string): Type of the vehicle (car, lorry, pickup truck).
        - active (bool): Indicates if the vehicle is active.

        Returns:
        - int: 1 if the vehicle was successfully added, 0 otherwise.
    */
    Vehicle *new_vehicle;

    if (type == "car")
    {
        new_vehicle = new Car(chassi, model, year, max_load_weight, max_load_volume, coordinates, active);
    }
    else if (type == "lorry")
    {
        new_vehicle = new Lorry(chassi, model, year, max_load_weight, max_load_volume, coordinates, active);
    }
    else if (type == "pickup truck")
    {
        new_vehicle = new PickupTruck(chassi, model, year, max_load_weight, max_load_volume, coordinates, active);
    }
    else
    {
        std::invalid_argument("Invalid type \n");
        return 0;
    }

    this->vehicles_list.push_back(new_vehicle);
    return 1;
}

int Garage::remove_vehicle(uint32_t id)
{
    /*
        Description: Removes a vehicle from the garage.

        Parameters:
        - id (uint32_t): ID of the vehicle to be removed.

        Returns:
        - int: 1 if the vehicle was successfully removed, 0 otherwise.
    */

    // Searching for the vehicle that will be excluded
    int64_t index = search_vehicle(this->vehicles_list, 0, this->vehicles_list.size(), id);

    // Deconstructing object and removing from the list
    delete vehicles_list[index];
    vehicles_list.erase(vehicles_list.begin() + index);

    return 1;
}
int64_t Garage::search_vehicle(std::vector<Vehicle *> list, int first_index, int last_index, int id)
{
    /*
        Description: Searches for a vehicle in the given list based on its ID.

        Parameters:
        - list (std::vector<Vehicle*>): List of vehicles to search in.
        - first_index (int): Index of the first element in the search range.
        - last_index (int): Index of the last element in the search range.
        - id (int): ID of the vehicle to search for.

        Returns:
        - int64_t: Index of the vehicle in the list if found, -1 otherwise.
    */

    // Using binary search to get the list index of vehicle
    int vector_size = last_index - first_index;
    if (vector_size < 1)
    {
        return -1;
    }
    int pivot = (last_index - first_index) / 2 + first_index;

    if (id > list[pivot]->get_id())
    {
        return search_vehicle(list, pivot, last_index, id);
    }
    else if (id < list[pivot]->get_id())
    {
        return search_vehicle(list, first_index, pivot, id);
    }
    else
    {
        return pivot;
    }
}

//******************************************************************//
//************************* GETTER FUNCTIONS ***********************//
//******************************************************************//

std::vector<Vehicle *> Garage::get_vehicles_list()
{
    /*
        Description: Gets the list of vehicles in the garage.

        Returns:
        - std::vector<Vehicle*>: List of vehicles.
    */
    return this->vehicles_list;
}

Vehicle *Garage::get_vehicle(uint32_t id)
{
    /*
        Description: Gets a vehicle instance from the garage based on its ID.

        Parameters:
        - id (uint32_t): ID of the vehicle to get.

        Returns:
        - Vehicle*: Pointer to the vehicle if found, NULL otherwise.
    */

    // Getting vehicle index
    int64_t vehicle_index = search_vehicle(this->vehicles_list, 0, this->vehicles_list.size(), id);

    // Checking if it was not found
    if (vehicle_index < 0)
    {
        std::cout << "Vehicle with id " << id << " not found in garage."
                  << "\n";
        return NULL;
    }

    return this->vehicles_list[vehicle_index];
}

std::vector<Vehicle *> Garage::get_active_vehicles()
{
    /*
        Description: Gets the list of active vehicles in the garage.

        Returns:
        - std::vector<Vehicle*>: List of active vehicles.
    */
    std::vector<Vehicle *> active_vehicles;

    for (Vehicle *vehicle : this->vehicles_list)
    {

        if (vehicle->get_active() != 1)
            continue;

        active_vehicles.push_back(vehicle);
    }

    return active_vehicles;
}

//******************************************************************//
//************************** DECONSTRUCTOR *************************//
//******************************************************************//

Garage::~Garage()
{
    // Nothing to do
}