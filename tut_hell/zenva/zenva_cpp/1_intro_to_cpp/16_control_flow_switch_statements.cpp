#include <iostream>

int main() {

  char trafficLight = 'g';
  int speed = 30;

  // switch statement
  switch (trafficLight) { // test variable's value
    case 'g':
      std::cout << "Go!\n";
      break; // to stop the evaluation of other cases
    case 'r':
      std::cout << "Stop!\n";
      break;
    case 'y':
      if (speed <= 30) {
        std::cout << "Speed up!\n";
      } else {
        std::cout << "Slow down!\n";
      }
      break;
    default:
      std::cout << "Unknown state!\n";
  }
}
