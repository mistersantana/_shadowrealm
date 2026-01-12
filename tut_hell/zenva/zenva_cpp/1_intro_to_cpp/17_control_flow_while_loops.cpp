#include <iostream>

int main() {

  int pos = 0; // starting position
  int endPos = 5; // ending position

  // while loop to print position until end position is reached
  while(pos <= endPos) {
    pos++; // increment current position
    // print the current position
    std::cout << "Current position is " << pos << std::endl;
  }
  std::cout << "You have reached the end!" << std::endl;

  pos = 0; // resetting the current position
  // do-while loop
  do {
    pos++;
    std::cout << "Current position is " << pos << std::endl;
  } while (pos < endPos);
  std::cout << "You have reached the end!" << std::endl;


  // CHALLENGE
  pos = 0;
  bool isGameOver = false;

  while (!isGameOver) {
    pos++;
    std::cout << "Current position is " << pos << std::endl;
    if (pos >= endPos) { // check position
      isGameOver = true;
    }
  }
  std::cout << "You have reached the end!" << std::endl;

}
