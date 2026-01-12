#include <iostream>

int main() {

  int age = 28; // variable
  int* intPtr = &age; // pointer to variable

  std::cout << intPtr << std::endl; // will print the hexadecimal address

  // increase the hexadecimal address to which the pointer points
  intPtr++;
  std::cout << intPtr << std::endl; // the address has increased by 4 bytes

  // the above logic can be applied to any type of pointer
  bool isOpen = false; // a boolean variable
  bool* boolPtr = &isOpen; // a boolean pointer

  std::cout << boolPtr << std::endl; // will print the hexadecimal address

  // increase the hexadecimal address to which the pointer points
  boolPtr++;
  std::cout << boolPtr << std::endl; // the address has increased by 1 byte

  // check how many bytes a variable type takes up
  std::cout << sizeof(bool) << std::endl;
  std::cout << sizeof(int) << std::endl;
  std::cout << sizeof(char) << std::endl;


  // CHALLENGE ---------------------------------------------------------------

  // 1.
  int i = 0; // stored at address = 0x00
  int* iPtr = &i;
  iPtr++; // what address does iPtr point to?
  // 0x04

  // 2.
  char a = 'a'; // stored at address 0x04
  char* aPtr = &a;
  aPtr--; // what address does aPtr point to?
  // 0x03

  // 3.
  bool b = true; // stored at address 0x06
  bool* bPtr = &b;
  bPtr++;
  bPtr++; // what address does bPtr point to?
  // 0x08

}
