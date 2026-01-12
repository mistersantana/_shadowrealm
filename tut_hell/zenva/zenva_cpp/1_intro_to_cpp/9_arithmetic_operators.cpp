#include <iostream>

int main() {

  // arithmetic operators
  // + - * / %

  int age = 28;
  std::cout << age << std::endl;
  
  // additional operators +
  std::cout << "Examples of additional operator" << std::endl;
  int newAge = age + 1;
  std::cout << newAge << std::endl;

  // change the original variable itself
  age = age + 2;
  std::cout << age << std::endl;

  // modulus operator %
  std::cout << "Examples of modulus operator" << std::endl;

  // get the remainder
  int modulusAge = age % 5;
  std::cout << modulusAge << std::endl;

  // observe the order of operations
  int modulusAge1;
  modulusAge1 = age + 1 % 5;
  std::cout<< modulusAge1 << std::endl;

  int modulusAge2;
  modulusAge2 = (age + 1) % 5;
  std::cout << modulusAge2 << std::endl;

  // using the addition operator for appending strings
  std::cout << "Examples of appending strings with the addition operator" << std::endl;

  std::string name = "Nimish";
  std::cout << name + " Narang" << std::endl;
}
