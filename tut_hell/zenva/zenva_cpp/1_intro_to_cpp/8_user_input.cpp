#include <iostream>

int main() {

  // declare a variable to store the input
  std::string input;

  // take in text input and store it in the variable
  std::cin >> input;

  //print the stored input back to the console
  std::cout << input;

  /* the cin function treats an input with spaces in it as being multiple inputs all separated by the spaces */
  // taking in multiple words as input
  std::string input1;
  std::string input2;
  std::cin >> input1 >> input2;
  std::cout << input1 << std::endl;
  std::cout << input2 << std::endl;

  // take in integer input
  int num;
  std::cin >> num;
  std::cout << num << std::endl;

  // 1. Prompt user for name
  std::string name;
  std::cout << "Enter your name: ";
  // 2. Take in and store user's name
  std::cin >> name;
  // 3. Print welcome message
  std::cout << "Hello, " << name << ". Welcome to The Program!" << std::endl;
}
