/** 
* Spring 2023 - Lab 03
* Last name: Cataluna
* First name: Kert Harvey
* GitHub username: kertharv
* Instructor: Genady Maryash
* Recitation Instructor: Prof. Zamansky
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reservoir.h"

double get_east_storage(std::string date) 
{
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) 
    {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string junk;
    getline(fin, junk);

    std::string rDate;
    double eastSt, eastEl, westSt, westEl;
    while(fin >> rDate >> eastSt >> eastEl >> westSt >> westEl) 
    { 
        fin.ignore(INT_MAX, '\n');
        if(rDate == date) 
        {
            return eastSt;
        }
    }
    fin.close();
    return 0;
}

double get_min_east() 
{
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) 
    {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string junk;
    getline(fin, junk);

    std::string rDate;
    double eastSt, eastEl, westSt, westEl;
    double minEast = INT_MAX;
    while(fin >> rDate >> eastSt >> eastEl >> westSt >> westEl) 
    { 
        fin.ignore(INT_MAX, '\n');
        if(eastSt < minEast) 
        {
            minEast = eastSt;
        }
    }
    fin.close();
    return minEast;
}

double get_max_east() 
{
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) 
    {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string junk;
    getline(fin, junk);

    std::string rDate;
    double eastSt, eastEl, westSt, westEl;
    double maxEast = INT_MIN;
    while(fin >> rDate >> eastSt >> eastEl >> westSt >> westEl) 
    { 
        fin.ignore(INT_MAX, '\n');;
        if(eastSt > maxEast) 
        {
            maxEast = eastSt;
        }
    }
    fin.close();
    return maxEast;
}

std::string compare_basins(std::string date) 
{
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) 
    {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string junk;
    getline(fin, junk);

    std::string rDate;
    double eastSt, eastEl, westSt, westEl;
    while(fin >> rDate >> eastSt >> eastEl >> westSt >> westEl) 
    { 
        fin.ignore(INT_MAX, '\n');
        if(rDate == date) 
        {
            if(eastEl > westEl) 
            {
                return "East";
            }
            else if(westEl > eastEl) 
            {
                return "West";
            }
            else if(eastEl == westEl) 
            {
                return "Equal";
            }
        }
    }
    fin.close();
    return 0;
}