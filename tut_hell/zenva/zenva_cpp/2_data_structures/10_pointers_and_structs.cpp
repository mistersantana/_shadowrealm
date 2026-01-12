#include <iostream>

// create a struct
struct house {
  std::string address;
  int beds;
  int baths;
  std::string owner;
} myHouse;

// function to change the owner of a house using pointers
void changeOwner(house *_house, std::string newOwner) {
  _house->owner = newOwner;
}

int main() {

  // assign an owner
  myHouse.owner = "Nimish";

  // create a struct pointer
  house *myHousePtr = &myHouse; // the type of this pointer is 'house'

  // to retrieve specific struct properties using the myHousePtr, use the -> syntax
  std::cout << myHousePtr->owner << std::endl;

  // modify the struct pointer
  myHousePtr->owner = "Zenva";
  std::cout << myHouse.owner << std::endl;

  // using a function to change a struct value
  changeOwner(myHousePtr, "Someone");
  std::cout << myHouse.owner << std::endl;

}
