#include <iostream>

int main() {

  // for loop to print a message 5 times
  for (int i = 0; i < 5; i++) {
    std::cout << "Hello!\n";
  }

  // CHALLENGE
  // convert the while loop from the previous lesson into a for loop

  //solution
  int pos = 0;
  int endPos = 5;

  for (pos = 1; pos <= endPos; pos++) {
    std::cout << "Current position: " << pos << std::endl;
  }
  std::cout << "You have reached the end!" << std::endl;

}
