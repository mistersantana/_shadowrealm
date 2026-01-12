#include <iostream>

int main() {
  // an integer
  // int age = 28;

  // the default value of an integer is zero
  int health;
  std::cout << health << std::endl;

  // assign a positive value
  health = 50;
  std::cout << health << std::endl;

  // assign a negative value
  health = -50;
  std::cout << health << std::endl;

  // unsigned integers will hold only positive values
  uint age = 28;
  std::cout << health << std::endl;

  // assigning negative values to unsigned integers is not allowed
  uint nAge = -28;
  std::cout << health << std::endl;

  // types can vary according to the range of number you want to consider
  short shortInt = 1;
  std::cout << shortInt << std::endl;

  long longInt = -45000;
  std::cout << longInt << std::endl;

  long long longLongInt = 497283412736817239;
  std::cout << longLongInt << std::endl;
  
}

