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
        EntryManager();
        EntryManager(std::string pathFile);
        ~EntryManager();

        std::string getPathFile();
        void setPathFile(std::string pathFile);

        int inputFileProcessing();
        void clearClients();
        void clearOrders();
};

#endif