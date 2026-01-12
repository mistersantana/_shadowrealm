#include <iostream>

int main() {

  // create an integer array
  int lotteryNumbers[] = {1, 2, 3, 4, 5, 6};
  std::cout << lotteryNumbers[0] << std::endl;

  // create int pointer that points to the array
  // not using the & operator when pointing to an array
  // lotteryPtr points to the address of the first element in lotteryNumbers
  int *lotteryPtr = lotteryNumbers;

  // dereferencing will return the first element of the array
  std::cout << *lotteryPtr << std::endl;


  lotteryPtr++; // the address pointed at moves forward by 4 bytes
  std::cout << *lotteryPtr << std::endl; // dereferencing will return the second element of the array
  
  lotteryPtr++; // the address pointed at moves forward by 4 more bytes
  std::cout << *lotteryPtr << std::endl; // dereferencing will return the third element of the array


  // using pointers to modify elements of the array
  // we are currently at the third element of the array
  *lotteryPtr = 10;
  std::cout << lotteryNumbers[2] << std::endl;

  // we can apply the same logic to constant arrays of characters
  const char *name = "Nimish"; // a character pointer
  std::cout << *name << std::endl; // dereferencing returns the first character
  name++; // now points to the second character
  std::cout << *name << std::endl;
  
}
