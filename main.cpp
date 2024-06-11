#include <iostream>
#include <array>
#include "include/all.hpp"

int main()
{
    // Creating a new Garage object
    Garage *garagem_do_tonho = new Garage();

    // Populating garagem_do_tonho with new vehicles.
    garagem_do_tonho->add_vehicle("XXX000XXX000", "Toyota Dyna", 1998, 3000, 60000, {0, 0}, "lorry", 1);
    garagem_do_tonho->add_vehicle("XXX000XXX111", "ABC Motors XYZ-1000", 2022, 4000, 60000, {20, 20}, "lorry", 1);
    garagem_do_tonho->add_vehicle("XXX000XXX222", "Fiat Uno Mille Economic", 2013, 500, 1000, {-30, -60}, "car", 1);
    garagem_do_tonho->add_vehicle("YYY111YYY333", "Fiat Palio", 2015, 550, 950, {60, 60}, "car", 1);
    garagem_do_tonho->add_vehicle("ZZZ222ZZZ444", "Toyota Corolla", 2018, 600, 900, {80, 80}, "car", 1);
    garagem_do_tonho->add_vehicle("WWW333WWW555", "Volkswagen Gol", 2016, 480, 800, {100, 100}, "car", 1);

    // Creating clients
    Client *cliente1 = new Client("Claudio", "123.456.789-09", "rua 1", "12344555", "example@org");
    Client *cliente2 = new Client("Marcelo", "987.654.321-00", "rua 2", "1234567", "email@mail");
    Client *cliente3 = new Client("Luiz Ernesto", "789.957.010-72", "rua 3", "9998271365", "mail@hotmail");

    // Creating orders
    Order *pedido1 = new Order(0, "Fogão 6 bocas", "car", {34.5, 32.1}, {11.3, 45.6}, 500, 40);
    Order *pedido2 = new Order(0, "Relógio do Ben 10", "car", {12.56}, {11.45}, 0.2, 0.15);
    Order *pedido3 = new Order(1, "Bazuca", "lorry", {13.99}, {44.55}, 5, 30);
    Order *pedido4 = new Order(2, "Pato de borracha para debugar", "lorry", {2.34}, {1.44}, 0.1, 0.1);

    // Entry Manager
    EntryManager *entry = new EntryManager();

    entry->set_path_file("input/dados_entregas_lite.csv");
    entry->input_file_processing();

    // Creating a new TransportManager object using garagem_do_tonho vehicles
    
    // Allocating new transports to be done

    TransportManager *controlador_do_tonho = new TransportManager(garagem_do_tonho);
    controlador_do_tonho->new_transport(pedido1, 0);
    controlador_do_tonho->new_transport(pedido2, 0);
    controlador_do_tonho->new_transport(pedido3, 0);
    controlador_do_tonho->new_transport(pedido4, 0);
    
    // Printing all transports to be done
    for(int i = 0; i < 6; i++)
    {
        controlador_do_tonho->print_pending_transports(i);
    }

    std::cout << std::endl;

    // Calling method to close transport
    controlador_do_tonho->close_transport(pedido1, "Paulo");

    // Printing all transports to be done
    for (int i = 0; i < 6; i++)
    {
        controlador_do_tonho->print_pending_transports(i);
    }

    std::cout << std::endl;

    return 0;
}