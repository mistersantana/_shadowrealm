#include <iostream>

// create an enumeration (enum)
enum traffic_light {
  red = 1, // change the assigned value to red
  yellow, // now yellow = 2
  green // now green = 3
} trafficLight;

int main() {

  // assign and test the value of any instance of traffic_light
  trafficLight = green;

  //testing using the enum value
  if (trafficLight == green) {
    std::cout << "Go\n";
  }

  // testing using the integer value
  if (trafficLight == 3) {
    std::cout << "Go\n";
  }


  // CHALLENGE ---------------------------------------------------------------
  // build a switch statement to test the traffic light
  switch(trafficLight) {
    case red:
      std::cout << "Stop\n";
      break;
    case yellow:
      std::cout << "Slow down\n";
      break;
    case green:
      std::cout << "Go\n";
      break;
  }

}
