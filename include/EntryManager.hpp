#ifndef _ENTRYMANAGER_H
#define _ENTRYMANAGER_H

#include <list>
#include "Client.hpp"
#include "Order.hpp"


class EntryManager
{
    private:
        std::string path_file;
        std::list<Client*>* clients;
        std::list<Order*>* orders;

    public:
        // CONSTRUCTOR
        EntryManager();
        EntryManager(std::string path_file);

        // GETTER FUNCTIONS
        std::string get_path_file();

        // SETTER FUNCTIONS
        void set_path_file(std::string path_file);

        // MAIN FUNCTIONS
        int input_file_processing();

        // CLEAR FUNCTIONS
        void clear_clients();
        void clear_orders();

        // DECONSTRUCTOR
        ~EntryManager();
};

#endif