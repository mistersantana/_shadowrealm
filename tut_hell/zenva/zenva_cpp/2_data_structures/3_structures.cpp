#include <iostream>

// structs are built outside of functions

// constructing a struct to model the properties of a house
struct house {
  std::string address;
  int numBedrooms;
  int numBathrooms;
} myHouse; // creating an instance of a 'house'

int main() {

  // accessing the properties of myHouse and setting their values
	myHouse.address = "123 1st Ave, Vancouver, Canada";
	myHouse.numBedrooms = 5;
	myHouse.numBathrooms = 2;

	// creating anouther instance of 'house'
	house yourHouse; // the data type of yourHouse is 'house'
	// assign some values
	yourHouse.address = "2 2nd Ave, Toronto, Canada";
	yourHouse.numBedrooms = 1;
	yourHouse.numBathrooms = 1;

	std::cout << yourHouse.address << std::endl;

}
