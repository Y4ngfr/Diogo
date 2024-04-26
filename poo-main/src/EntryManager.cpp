#include <iostream>
#include <fstream>
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
    std::list<Client*>::iterator clientIt;
    std::list<Order*>::iterator orderIt;
    std::fstream inputFile;
    char buffer = '\0';

    inputFile.open("../input/dados_entregas.csv", std::ios::in);

    if(!inputFile.is_open()){
        std::cout << "[INPUT ERROR]: file not found";
        return -1;
    }

    inputFile.get(buffer);

    std::cout << buffer;

    inputFile.close();

    return 0;
}