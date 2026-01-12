#include <iostream>
#include <ostream>

int main() {
  // boolean variables are asking a yest or no question
  bool isOn = true;
  bool isGameOver = false;

  // printing out the value of a boolean
  // 1 for true and 0 for false
  std::cout << isOn << std::endl;
  std::cout << isGameOver << std::endl;

  // reassigning a value to a variable
  isGameOver = true;
  std::cout << isGameOver << std::endl;
}
