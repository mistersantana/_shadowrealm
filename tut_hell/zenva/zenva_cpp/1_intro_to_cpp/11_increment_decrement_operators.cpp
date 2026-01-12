#include <iostream>

int main() {

  // increment and decrement operators
  // ++ --

  int age = 28;

  // incrementing the value of age
  // age = age + 1;
  // age += 1;
  age++; // using the increment operator behind the variable
  std::cout << age << std::endl;

  // decrementing the value of age
  age--; // using the decrement operator behind the variable
  std::cout << age << std::endl;

  int newAge1 = age++; // storing the existing value into a new variable first, and then incrementing
  age = 28; // resetting the age
  int newAge2 = ++age; // incrementing first and then storing the new value into the new variable
  std::cout << newAge1 << std::endl;
  std::cout << newAge2 << std::endl;


  // CHALLENGE --------------------------------------------------------------

  // 1. What is the end result?
  int a = 0;
  int result = a - 5 * 2 + 20 / 2;

  // solution
  std::cout << result << std::endl;


  // 2. Can we change the equation to a positive value?
  // solution
  int result2 = (a - 5 * 2 + 20) / 2;
  std::cout << result2 << std::endl;


  // 3. What is the end result?
  int b = 10;
  b += 2 * 7;

  // solution
  std::cout << b << std::endl;


  // 4. I want to spell my full name. What is wrong with this equation?
  std::string firstName = "Nimish";
  std::string lastName = "Narang";
  std::string fullName = firstName + lastName;
  std::cout << fullName << std::endl;

  //solution
  std::string firstName2 = "Nimish";
  std::string lastName2 = "Narang";
  std::string fullName2 = firstName2 + " " + lastName2;
  std::cout << fullName2 << std::endl;


  // 5. What are the value of c and d?
  int c = 1;
  int d = c--;

  // solution
  std::cout << c << std::endl;
  std::cout << d << std::endl;

}
