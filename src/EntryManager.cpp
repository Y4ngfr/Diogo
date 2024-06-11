#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include "../include/EntryManager.hpp"
#include "../include/GeoShell.hpp"

//******************************************************************//
//*************************** CONSTRUCTOR **************************//
//******************************************************************//

EntryManager::EntryManager()
{
/*
    Description: Basic Constructor for EntryManager class.
*/

    this->clients = nullptr;
    this->orders = nullptr;
    this->path_file = "\0";
}

EntryManager::EntryManager(std::string path_file)
{
/*
    Description: Onverload Constructor for EntryManager class.

    Parameters:
    - path_file (std::string): The input file path.
*/

    this->clients = nullptr;
    this->orders = nullptr;
    this->path_file = path_file;
}

//******************************************************************//
//************************* SETTER FUNCTIONS ***********************//
//******************************************************************//

void EntryManager::set_path_file(std::string path_file)
{
    /*
    Description: Sets the path_file of the EntryManager.

    Parameters:
    - path_file (std::string): The input file path.
    */

    this->path_file = path_file;
}

//******************************************************************//
//************************* GETTER FUNCTIONS ***********************//
//******************************************************************//

std::string EntryManager::get_path_file()
{
    /*
    Description: Gets the path_file of the EntryManager.

    Returns:
    - std::string: The input file path.
    */

    return this->path_file;
}

//*****************************************************************//
//************************* CLEAR FUNCTIONS ***********************//
//*****************************************************************//

void EntryManager::clear_clients()
{
/*
    Description: Removes and clears all instances within the 
    customer list (does not delete the list).
*/

    std::list<Client*>::iterator it;

    it = this->clients->begin();

    while(it != this->clients->end())
    {
        Client* aux;

        aux = (*it);
        it = this->clients->erase(it);

        delete aux;
    }

    delete this->clients;
}

void EntryManager::clear_orders()
{
/*
    Description: Removes and clears all instances within the 
    orders list (does not delete the list).
*/

    std::list<Order*>::iterator it;

    it = this->orders->begin();

    while(it != this->orders->end())
    {
        Order* aux;

        aux = (*it);
        it = this->orders->erase(it);

        delete aux;
    }

    delete this->orders;
}

//****************************************************************//
//************************* MAIN FUNCTIONS ***********************//
//****************************************************************//

int EntryManager::input_file_processing()
{
/*
    Description: Reads the file defined in the path_file attribute and 
    instantiates all requested objects into the customer and order lists

    Returns:
    - returns -1 returns -1 if an error occurs and 0 if completed successfully
*/
    
    std::fstream input_file;
    std::string client_buffer[5], order_buffer[5];

    bool ignore_comma = false;

    input_file.open(this->path_file, std::ios::in);

    if(!(input_file.is_open())){
        std::cout << "[INPUT ERROR]: file not found";
        return -1;
    }

    this->clients = new std::list<Client*>;
    this->orders = new std::list<Order*>;

    input_file.ignore(200, '\n');
    int t=0;
    while(!(input_file.eof()))
    {
        Client *new_client;
        Order *new_order;

        std::string description = "lorem ipsum";
        std::string type_of_transportation = "lorem ipsum";
        
        std::array<double, 2UL> collection_adress;
        std::array<double, 2UL> delivery_adress;

        double weight;
        double volume;

        GeoShell geoShellObj;

        for(int i = 0; i < 5; i++)
        {
            if(ignore_comma == false){
                std::getline(input_file, client_buffer[i], ',');
            }
            else{
                client_buffer[i] = "";
                do{
                    client_buffer[i] += input_file.get();

                }while(input_file.peek() != '"');

                ignore_comma = false;
                input_file.ignore(2, EOF);
            }

            if(input_file.peek() == '"'){
                ignore_comma = true;
                input_file.get();
            }
        }

        for(int i = 0; i < 5; i++)
        {
            if(ignore_comma == false)
            {
                i != 4 ? 
                    std::getline(input_file, order_buffer[i], ','):
                    std::getline(input_file, order_buffer[i], '\n');
            }
            else{
                order_buffer[i] = "";
                do{
                    order_buffer[i] += input_file.get();

                }while(input_file.peek() != '"');

                ignore_comma = false;
                input_file.ignore(2, EOF);
            }

            if(input_file.peek() == '"'){
                ignore_comma = true;
                input_file.get();
            }
        }

        std::cout << "Client Buffer:" << std::endl;
        std::cout << "1: " << client_buffer[0] << std::endl;
        std::cout << "2: " << client_buffer[1] << std::endl;
        std::cout << "3: " << client_buffer[2] << std::endl;
        std::cout << "4: " << client_buffer[3] << std::endl;
        std::cout << "5: " << client_buffer[4] << std::endl << std::endl;

        std::cout << "Order Buffer:" << std::endl;
        std::cout << "1: " << order_buffer[0] << std::endl;
        std::cout << "2: " << order_buffer[1] << std::endl;
        std::cout << "3: " << order_buffer[2] << std::endl;
        std::cout << "4: " << order_buffer[3] << std::endl;
        std::cout << "5: " << order_buffer[4] << std::endl << std::endl;

        new_client = new Client(client_buffer[0], client_buffer[1], client_buffer[2], client_buffer[3], client_buffer[4]);

        std::string substring1, substring2;

        substring1 = order_buffer[0].substr(order_buffer[0].find('\n') + 1, (order_buffer[0].find('\n', order_buffer[0].find('\n') + 1)) - (order_buffer[0].find('\n') + 2));
        substring2 = order_buffer[1].substr(order_buffer[1].find('\n') + 1, (order_buffer[1].find('\n', order_buffer[1].find('\n') + 1)) - (order_buffer[1].find('\n') + 2));

        while(substring1.find(" ") != std::string::npos)
        {
            substring1.replace(substring1.find(" "), 1, "+");
        }

        while(substring2.find(" ") != std::string::npos)
        {
            substring2.replace(substring2.find(" "), 1, "+");
        }

        collection_adress = geoShellObj.mapsRequest(substring1);
        delivery_adress = geoShellObj.mapsRequest(substring2);

        // std::cout << substring1 << std::endl;
        // std::cout << substring2 << std::endl;
        // std::cout << collection_adress[0] << " " << collection_adress[1] << std::endl;
        // std::cout << delivery_adress[0] << " " << delivery_adress[1] << std::endl;

        weight = std::stod(order_buffer[2]);
        volume = std::stod(order_buffer[3]);

        new_order = new Order(new_client->get_id(), description, type_of_transportation, collection_adress, delivery_adress, weight, volume);

        this->clients->push_back(new_client);
        this->orders->push_back(new_order);

        std::cout << std::endl;
    }

    input_file.close();

    return 0;
}

//******************************************************************//
//************************** DECONSTRUCTOR *************************//
//******************************************************************//

EntryManager::~EntryManager()
{
/*
    Description: clears all lists and then deletes them
*/
    
    clear_clients();
    clear_orders();

    delete this->clients;
    delete this->orders;
}