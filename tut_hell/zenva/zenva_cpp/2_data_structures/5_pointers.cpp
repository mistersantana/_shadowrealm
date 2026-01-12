#include <iostream>

int main() {

  // create an integer variable
  int age = 28;

  // create a pointer to the above integer
  // this pointer will store where the variable is stored in memory
  // pointer type is int because the variable is of type int
  // pointer is indicated with the * operator
  int *agePtr = &age; // address of the variable is retrieved with the & operator

  std::cout << age << std::endl;
  std::cout << agePtr << std::endl; // will print the hexadecimal address

  // dereferencing a pointer
  // retrieve the value stored at the address indicated by the pointer
  int newAge = *agePtr;
  std::cout << newAge << std::endl;
}
