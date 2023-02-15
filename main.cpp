// add your code as appropriate 
/** 
* Spring 2023 - Lab 03
* Last name: Cataluna
* First name: Kert Harvey
* GitHub username: kertharv
* Instructor: Genady Maryash
* Recitation Instructor: Prof. Zamansky
*/
#include <iostream>
#include "reservoir.h"
#include "reverseorder.h"

int main()
{
  // East basin storage
  std::cout << "Enter Date: 06/30/2018\n" << "East basin storage: " << get_east_storage("06/30/2018") << " billion gallons\n\n";
  std::cout << "Enter Date: 08/01/2018\n" << "East basin storage: " << get_east_storage("08/01/2018") << " billion gallons\n\n";
  std::cout << "Enter Date: 10/15/2018\n" << "East basin storage: " << get_east_storage("10/15/2018") << " billion gallons\n\n";
  
  // Minimum and maxium storage in East basin
  std::cout << "Minimum storage in East basin: " << get_min_east() << " billion gallons\n\n"; 
  std::cout << "Maximum storage in East basin: " << get_max_east() << " billion gallons\n\n";
  
  // Basin elevation comparison
  std::cout << "Enter Date: 09/17/2018\n" << "The basin with the higher elevation is: " << compare_basins("09/17/2018") << "\n\n";
  std::cout << "Enter Date: 03/03/2018\n" << "The basin with the higher elevation is: " << compare_basins("03/03/2018") << "\n\n";
  std::cout << "Enter Date: 12/25/2018\n" << "The basin with the higher elevation is: " << compare_basins("12/25/2018") << "\n\n";

  // Reverse Order
  std::cout << "Enter earlier date: 05/28/2018\n" << "Enter later date: 06/05/2018\n\n";
  
  reverse_order("05/28/2018", "06/05/2018");

  std::cout << "\nEnter earlier date: 03/22/2018\n" << "Enter later date: 03/26/2018\n\n";
  
  reverse_order("03/22/2018", "03/26/2018");

  return 0;
}