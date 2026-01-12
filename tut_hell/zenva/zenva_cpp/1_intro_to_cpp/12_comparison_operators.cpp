#include <iostream>

int main() {

  // comparison operators
  // == != > >= < <=
  
  int age = 28;
  int minAge = 18;

  // check if age is greater than or equal to minimum allowed age
  bool isAdult = age >= minAge; // this is a boolean result
  std::cout << isAdult << std::endl;

  // use parentheses for comparison operators in print statements
  std::cout << (age >= minAge) << std::endl;

  // the following two pring statements are the same
  std::cout << (isAdult == true) << std::endl;
  std::cout << isAdult << std::endl;


  // comparing other variable types
  // you can compare variables as long as they are of the same type
  std::string a = "a";
  std::string b = "b";

  bool result1 = a == b;
  std::cout << result1 << std::endl;

  bool result2 = a < b; // the result is based on the position of the letter in the alphabet
  std::cout << result2 << std::endl;

}
