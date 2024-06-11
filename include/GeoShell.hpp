#ifndef GEOSHELL_H
#define GEOSHELL_H

#include <iostream>
#include <array>

class GeoShell
{
public:
    // FEATURES
    static std::array<double, 2> get_coordinates(std::string location);
    static std::array<double, 2> mapsRequest(std::string location);
    static size_t myFunctionCallBack(char* contents, size_t size, size_t nmemb, char* buffer_in);
};
#endif