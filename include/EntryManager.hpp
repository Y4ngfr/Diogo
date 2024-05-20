#ifndef _ENTRYMANAGER_H
#define _ENTRYMANAGER_H

#include <list>
#include "Client.hpp"
#include "Order.hpp"


class EntryManager
{
    private:
        std::string pathFile;
        std::list<Client*>* clients;
        std::list<Order*>* orders;

    public:
        // CONSTRUCTOR
        EntryManager();
        EntryManager(std::string pathFile);

        // GETTER FUNCTIONS
        std::string getPathFile();

        // SETTER FUNCTIONS
        void setPathFile(std::string pathFile);

        // MAIN FUNCTIONS
        int inputFileProcessing();

        // CLEAR FUNCTIONS
        void clearClients();
        void clearOrders();

        // DECONSTRUCTOR
        ~EntryManager();
};

#endif