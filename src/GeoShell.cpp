#include <fstream>
#include <string>
#include <algorithm>
#include <curl/curl.h>
#include "../include/GeoShell.hpp"

//******************************************************************//
//**************************** FEATURES ****************************//
//******************************************************************//

std::array<double, 2> GeoShell::get_coordinates(std::string location)
{
    /*
        Description: Retrieves the coordinates of a location using GeoShell.

        Parameters:
        - location (std::string): The location for which to retrieve coordinates.

        Returns:
        - std::array<double, 2>: An array containing the latitude and longitude of the location.
    */

    // Getting file path created by GeoShell
    std::string file_name = location;
    std::replace(file_name.begin(), file_name.end(), ' ', '_');
    std::string path = "./GeoShell/.coordinates/" + file_name;

    // Trying to open previous requests
    std::ifstream file(path);

    // Checking if file doesn't exist
    if (!file.is_open())
    {
        // Preparing query
        std::string query = location;
        std::replace(query.begin(), query.end(), ' ', '+');

        // Setting and running command
        std::string command = "bash ./GeoShell/get_coordinates.sh \"" + query + "\"";
        std::system(command.c_str());

        // Opening output file
    }
    else
    {
        file.close();
    }

    // Opening output file
    file.open(path);

    // Declaring the coordinates array
    std::array<double, 2> coordinates;

    // Getting coordinates
    file >> coordinates[0];
    file >> coordinates[1];

    // Closing file
    file.close();

    // Returning coordinates
    return coordinates;
}

std::array<double, 2> GeoShell::mapsRequest(std::string location)
{
    CURL *curl;
    CURLcode res;
    std::string read_buffer, substring, url;
    size_t pos, i, offset;
    double lat, lon;
    std::array<double,2> coordinates;

    curl = curl_easy_init();

    if(curl){
        url = "https://www.google.com/maps/search/" + location;
        std::cout << url << std::endl;

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, myFunctionCallBack);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &read_buffer);

        res = curl_easy_perform(curl);

        if(res != CURLE_OK){
            std::cout << "Erro ao realizar a requisição: " << curl_easy_strerror(res) << std::endl;
            curl_easy_cleanup(curl);
            return {0.0,0.0};
        }

        curl_easy_cleanup(curl);
    }
    else{
        std::cout << "Erro ao inicializar o libcurl" << std::endl;
        return {0.0,0.0};
    }

    pos = read_buffer.find("APP_INITIALIZATION_STATE");

    if(pos == std::string::npos){
        std::cout << "Bloqueado" << std::endl;
        return {0.0, 0.0};
    }

    std::cout << read_buffer << std::endl;

    i = pos;
    while(read_buffer[i] != ',') i++;

    offset = i - pos + 1;

    while(read_buffer[i] != ']') i++;
    substring = read_buffer.substr(pos + offset, i - (pos + offset));
    exit(0);

    lat = std::stod(substring.substr(substring.find(',') + 1));
    lon = std::stod(substring.substr(0, substring.find(',')));

    return {lat, lon};
}

size_t GeoShell::myFunctionCallBack(char* contents, size_t size, size_t nmemb, char* buffer_in)
{
    ((std::string*)buffer_in)->append((char*)contents, size * nmemb);
    return size * nmemb;
}