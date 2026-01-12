#include <iostream>

// a function that takes parameters as input
void printFullName(std::string first, std::string last) {
  // parameters are treated as variables inside a function
  std::string fullName = first + " " + last;
  std::cout << fullName << std::endl;
}

int main() {

  printFullName("Mr.", "Santana");
}
