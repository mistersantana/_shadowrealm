#include <iostream>

int main() {

  // assignment operator =

  //used to store a value into a variable
  int age = 28;

  // assign the value of a variable to another variable
  int newAge = age;

  age = 29;

  std::cout << age << std::endl;
  std::cout << newAge << std::endl;

  // arithmetic and assignment combination
  // age = age + 1;
  age += 1; // this is the shorthand way of performing the above
  std::cout << age << std::endl;

  // the same logic applies to strings
  std::string name = "Nimish";
  name += " Narang";
  std::cout << name << std::endl;
  
}
