#include <iostream>

int main() {

  // int lotteryNumber[] = {1, 2, 3, 4, 5, 6};

  // creating an array from scratch
  int first = 1; // first element in array
  int *lotteryPtr = &first; // pointer to first element

  std::cout << *lotteryPtr << std::endl;

  // create the remaining elements of the array in their respective blocks of memory
  lotteryPtr++; // increment the pointer
  *lotteryPtr = 2; // assign the second element's value
  // repeat until all elements are assigned
  lotteryPtr++;
  *lotteryPtr = 3;
  lotteryPtr++;
  *lotteryPtr = 4;
  lotteryPtr++;
  *lotteryPtr = 5;
  lotteryPtr++;
  *lotteryPtr = 6;


  // CHALLENGE --------------------------------------------------------------

  int lotteryNumbers[6];

  // 1. build the lotteryNumbers array using the regular syntax
  for (int i = 0; i < 6; i++) {
    lotteryNumbers[i] = i + 1;
  }
  std::cout << lotteryNumbers[5] << std::endl;


  // 2. build the lotteryNumbers array through the use of pointers
  int *lotteryPtr2 = lotteryNumbers;
  for (int i = 0; i < 6; i++) {
    *lotteryPtr2 = i + 1;
    lotteryPtr2++;
  }
  std::cout << lotteryNumbers[5] << std::endl;

}
