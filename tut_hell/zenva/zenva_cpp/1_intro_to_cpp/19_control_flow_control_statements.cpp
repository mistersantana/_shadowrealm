#include <iostream>

int main() {

  int pos = 0;
  int endPos = 10;
  int itemPos = 2; // position of an item
  int enemyPos = 6; // position of an enemy

  while (pos < endPos)  {
    pos++;

    // check if there's an item in the current position
    if (pos == itemPos) {
      std::cout << "Item found!" << std::endl;
      continue; // skip the rest of the code inside the loop and move to the next iteration
    } else if (pos == enemyPos) {
      std::cout << "Enemy collision!" << std::endl;
      break; // break out of the entire while loop
    }

    // statement to print by default
    std::cout << "Empty space!" << pos << std::endl;
    
  }

}
