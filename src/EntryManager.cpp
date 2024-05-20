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
    this->pathFile = "\0";
}

EntryManager::EntryManager(std::string pathFile)
{
/*
    Description: Onverload Constructor for EntryManager class.

    Parameters:
    - pathFile (std::string): The input file path.
*/

    this->clients = nullptr;
    this->orders = nullptr;
    this->pathFile = pathFile;
}

//******************************************************************//
//************************* SETTER FUNCTIONS ***********************//
//******************************************************************//

void EntryManager::setPathFile(std::string pathFile)
{
    /*
    Description: Sets the pathFile of the EntryManager.

    Parameters:
    - pathFile (std::string): The input file path.
    */

    this->pathFile = pathFile;
}

//******************************************************************//
//************************* GETTER FUNCTIONS ***********************//
//******************************************************************//

std::string EntryManager::getPathFile()
{
    /*
    Description: Gets the pathFile of the EntryManager.

    Returns:
    - std::string: The input file path.
    */

    return this->pathFile;
}

//*****************************************************************//
//************************* CLEAR FUNCTIONS ***********************//
//*****************************************************************//

void EntryManager::clearClients()
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

void EntryManager::clearOrders()
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

int EntryManager::inputFileProcessing()
{
/*
    Description: Reads the file defined in the pathFile attribute and 
    instantiates all requested objects into the customer and order lists

    Returns:
    - returns -1 returns -1 if an error occurs and 0 if completed successfully
*/
    
    std::fstream inputFile;
    std::string clientBuffer[5], orderBuffer[5];

    bool ignoreComma = false;

    inputFile.open(this->pathFile, std::ios::in);

    if(!(inputFile.is_open())){
        std::cout << "[INPUT ERROR]: file not found";
        return -1;
    }

    this->clients = new std::list<Client*>;
    this->orders = new std::list<Order*>;

    inputFile.ignore(200, '\n');

    while(!(inputFile.eof()))
    {
        Client *newClient;
        Order *newOrder;

        std::string description = "lorem ipsum";
        std::string typeOfTransportation = "lorem ipsum";
        
        std::array<double, 2UL> collectionAdress;
        std::array<double, 2UL> deliveryAdress;

        double weight;
        double volume;

        GeoShell geoShellObj;

        for(int i = 0; i < 5; i++)
        {
            if(ignoreComma == false){
                std::getline(inputFile, clientBuffer[i], ',');
            }
            else{

                do{
                    clientBuffer[i] += inputFile.get();

                }while(inputFile.peek() != '"');

                ignoreComma = false;
                inputFile.ignore(2, EOF);
            }

            if(inputFile.peek() == '"'){
                ignoreComma = true;
                inputFile.get();
            }
        }

        for(int i = 0; i < 5; i++)
        {
            if(ignoreComma == false)
            {
                i != 4 ? 
                    std::getline(inputFile, orderBuffer[i], ','):
                    std::getline(inputFile, orderBuffer[i], '\n');
            }
            else{

                do{
                    orderBuffer[i] += inputFile.get();

                }while(inputFile.peek() != '"');

                ignoreComma = false;
                inputFile.ignore(2, EOF);
            }

            if(inputFile.peek() == '"'){
                ignoreComma = true;
                inputFile.get();
            }
        }

        /*std::cout << "Client Buffer:" << std::endl;
        std::cout << "1: " << clientBuffer[0] << std::endl;
        std::cout << "2: " << clientBuffer[1] << std::endl;
        std::cout << "3: " << clientBuffer[2] << std::endl;
        std::cout << "4: " << clientBuffer[3] << std::endl;
        std::cout << "5: " << clientBuffer[4] << std::endl << std::endl;

        std::cout << "Order Buffer:" << std::endl;
        std::cout << "1: " << orderBuffer[0] << std::endl;
        std::cout << "2: " << orderBuffer[1] << std::endl;
        std::cout << "3: " << orderBuffer[2] << std::endl;
        std::cout << "4: " << orderBuffer[3] << std::endl;
        std::cout << "5: " << orderBuffer[4] << std::endl << std::endl;*/

        newClient = new Client(clientBuffer[0], clientBuffer[1], clientBuffer[2], clientBuffer[3], clientBuffer[4]);

        //collectionAdress = geoShellObj.get_coordinates(orderBuffer[0]);
        //deliveryAdress = geoShellObj.get_coordinates(orderBuffer[1]);
        collectionAdress = {1.3, 2.3};
        deliveryAdress = {0.4, 1.2};

        weight = std::stod(orderBuffer[2]);
        volume = std::stod(orderBuffer[3]);

        newOrder = new Order(newClient->get_id(), description, typeOfTransportation, collectionAdress, deliveryAdress, weight, volume);

        this->clients->push_back(newClient);
        this->orders->push_back(newOrder);
    }

    inputFile.close();

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
    
    clearClients();
    clearOrders();

    delete this->clients;
    delete this->orders;
}