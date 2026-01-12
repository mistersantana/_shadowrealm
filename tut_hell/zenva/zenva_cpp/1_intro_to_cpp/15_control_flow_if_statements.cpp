#include <iostream>

int main() {

  char trafficLight = 'g';
  int speed = 30;

  // if statement
  if (trafficLight == 'g') {
    std::cout << "Go!\n";
  } else if (trafficLight == 'r') { // else-if statement
    std::cout << "Stop!\n";
  } else if (trafficLight == 'y') { // else-if statement
    // std::cout << "Slow down!\n";

    // challenge
    // nested if-else statements
    if (speed >= 30) {
      std::cout << "Speed up!\n";
    } else {
      std::cout << "Slow down!\n";
    }
  } else { // else statement
    std::cout << "Unknown state!\n";
  }

}
