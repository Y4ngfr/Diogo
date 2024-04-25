#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>

class Client
{
private:
    static uint32_t new_id;
    uint32_t id;
    std::string name;
    std::string cpf;

public:
    // CONSTRUCTOR
    Client(
        std::string name,
        std::string cpf);

    // HELPER FUNCTIONS
    int validate_document(std::string document, std::string document_type);

    // GETTER FUNCTIONS
    unsigned int get_id();

    // OPERATOR FUNCTIONS
    friend std::ostream &operator<<(std::ostream &os, const Client *clt);
    bool operator==(Client &other);

    // CONSTRUCTOR
    ~Client();
};

#endif