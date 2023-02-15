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
#include "reverseorder.h"

void reverse_order(std::string date1, std::string date2) 
{
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) 
    {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string junk;
    getline(fin, junk);

    double eastSt, eastEl, westSt, westEl;
    double rArray[365];
    std::string rDate;
    std::string dateArray[365];
    bool found = false;
    int x = 0;
    while(fin >> rDate >> eastSt >> eastEl >> westSt >> westEl) 
    { 
        fin.ignore(INT_MAX, '\n');
       if(rDate == date1) 
       {
           found = true;
       }   
       if(found) 
       {
            rArray[x] = westEl;
            dateArray[x] = rDate;
            x++;
       }
        if(rDate == date2) 
        {
            found = false;
        }
    }
    fin.close();
    for(int i = x - 1; i >= 0; i--)
    {
        std::cout << dateArray[i] << "\t" << rArray[i] << " ft" << std::endl;
    }
}