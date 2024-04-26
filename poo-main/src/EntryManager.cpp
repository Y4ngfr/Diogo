#include <iostream>
#include <fstream>
#include <string>
#include "../include/EntryManager.hpp"

EntryManager::EntryManager()
{
    this->clients = nullptr;
    this->orders = nullptr;
    this->pathFile = "\0";
}

EntryManager::EntryManager(std::string pathFile)
{
    this->clients = nullptr;
    this->orders = nullptr;
    this->pathFile = pathFile;
}

EntryManager::~EntryManager()
{
    clearClients();
    clearOrders();

    delete this->clients;
    delete this->orders;
}

void EntryManager::clearClients()
{
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

int EntryManager::inputFileProcessing()
{
    std::fstream inputFile;
    std::string clientBuffer[5], orderBuffer[5];
    std::string typeOfTransportation = "lorem ipsum";
    std::string description = "lorem ipsum";

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
        Client* entryClient;
        Order* entryOrder;
        int i;

        for(i = 0; i < 5; i++){
            std::getline(inputFile, clientBuffer[i], ',');
        }

        for(i = 0; i < 5; i++){
            std::getline(inputFile, orderBuffer[i], ',');
        }

        entryClient = new Client(clientBuffer[0], clientBuffer[1], clientBuffer[2], clientBuffer[3], clientBuffer[4]);
        entryOrder = new Order(entryClient->get_id(), description, typeOfTransportation, orderBuffer[0], orderBuffer[1], std::stod(orderBuffer[2]), std::stod(orderBuffer[3]));
        
        this->clients->push_front(entryClient);
        this->orders->push_front(entryOrder);
    }

    inputFile.close();

    return 0;
}

void EntryManager::setPathFile(std::string pathFile)
{
    this->pathFile = pathFile;
}

std::string EntryManager::getPathFile()
{
    return this->pathFile;
}