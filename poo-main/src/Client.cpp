#include <iostream>
#include "../include/Client.hpp"

uint32_t Client::new_id = 0;

//******************************************************************//
//************************** CONSTRUCTOR ***************************//
//******************************************************************//

Client::Client(
    std::string name,
    std::string cpf,
    std::string adress,
    std::string phone,
    std::string email)
{
    /*
        Description: Client constructor.

        Parameters:
        - name (std::string): Client's name.
        - cpf (std::string): Client's CPF number.
    */

    // Returning error if document is not valid
    if (!(this->validate_document(cpf, "cpf")))
        throw std::invalid_argument("[VALUE ERROR]: Invalid CPF");

    // Setting attributes
    this->id = Client::new_id++;
    this->cpf = cpf;
    this->name = name;
    this->adress = adress;
    this->phone = phone;
    this->email = email;
}

//******************************************************************//
//************************ HELPER FUNCTIONS ************************//
//******************************************************************//

int Client::validate_document(std::string document, std::string document_type)
{
    /*
        Description: Validates a document based on its type.

        Parameters:
        - document (std::string): Document to be validated.
        - document_type (std::string): Type of the document to be validated.

        Returns:
        - int: 1 if the document is valid, 0 otherwise.
    */
    if (document_type == "cpf")
    {

        std::string cpf_in_validation = document;

        // Checks if the document size is correct
        if (cpf_in_validation.size() != 14)
        {
            std::cout << "[VALUE ERROR]: Invalid CPF size";
            return 0;
        }

        // Excluding separators characters
        cpf_in_validation.replace(3, 1, "");
        cpf_in_validation.replace(6, 1, "");
        cpf_in_validation.replace(9, 1, "");

        // Verifies if all characters are in the accept range
        for (char character : cpf_in_validation)
        {
            if ((character - '0' < 0) || (character - '0' > 9))
            {
                std::cout << "[VALUE ERROR]: Invalid CPF characters";
                return 0;
            }
        }

        // Getting first verification digit
        int sum = 0;
        for (int i = 0; i < 9; i++)
            sum += (cpf_in_validation[i] - '0') * (i + 1);
        int first_verification_digit = sum % 11 % 10;

        // Checking the first verification digit
        if (first_verification_digit != (cpf_in_validation[9] - '0'))
        {
            std::cout << "[VALUE ERROR]: Invalid CPF";
            return 0;
        }

        // Getting second verification digit
        sum = 0;
        for (int i = 0; i < 10; i++)
            sum += (cpf_in_validation[i] - '0') * (i);
        int second_verification_digit = sum % 11 % 10;

        // Checking the second verification digit
        if (second_verification_digit != (cpf_in_validation[10] - '0'))
        {
            std::cout << "[VALUE ERROR]: Invalid CPF";
            return 0;
        }

        return 1;
    }
    else
    {
        std::cout << "[VALUE ERROR]: Invalid document type";
        return 0;
    }
}

//******************************************************************//
//************************ GETTER FUNCTIONS ************************//
//******************************************************************//

uint32_t Client::get_id()
{
    /*
    Description: Gets the ID of the client.

    Returns:
    - uint32_t: The ID of the client.
    */

    return this->id;
}

//******************************************************************//
//********************* OPERATORS OVERLOADING **********************//
//******************************************************************//

std::ostream &operator<<(std::ostream &os, const Client *clt)
{
    std::string censored_cpf = clt->cpf;
    censored_cpf.replace(4, 3, "***").replace(8, 3, "***");
    os << "-------------------- Client --------------------"
       << "\n";
    os << "Name: " << clt->name << "\n";
    os << "CPF: " << censored_cpf << "\n";
    os << "------------------------------------------------"
       << "\n\n";

    return os;
}

bool Client::operator==(Client &other)
{
    return this->id == other.id;
}

//******************************************************************//
//************************* DECONSTRUCTOR **************************//
//******************************************************************//

Client::~Client()
{
    // Nothing to do
}