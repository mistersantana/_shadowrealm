#include <iostream>

// creating a struct for the details of a home owner
struct home_owner {
  std::string firstName;
  std::string lastName;
  int age;
} nimish; // creating an instance

// creating a struct for the components of an address
struct address {
  int streeNumber;
  std::string streetName;
  std::string city;
  std::string country;
} myAddress; // creating an instance

// creating a nested struct
struct house {
  address address; // this is of type 'address' from the struct above
  int numBedrooms;
  int numBathroom;
  home_owner owner; // this is the 'home-owner' from the struct created above
} myHouse;


int main() {

  // setting the details of the 'nimish' instance
  nimish.firstName = "Nimish";
  nimish.lastName = "Narang";
  nimish.age = 28;

  // setting the values of the myAddress instance
  myAddress.streeNumber = 1;
  myAddress.streetName = "1st Ave";
  myAddress.city = "Vancouver";
  myAddress.country = "Canada";

  // setting the values of the myHouse instance
  myHouse.address = myAddress; // entire struct of myAddress has been assigned
  myHouse.numBedrooms = 3;
  myHouse.numBathroom = 2;
  myHouse.owner = nimish;

  // we cannot print the entire struct directly
  // std::cout << myHouse.address; // This will give an error if printed

  //we can use 'chaining' to access and print the nested struct properties
  std::cout << myHouse.address.streetName << std::endl;
  std::cout << myHouse.owner.firstName << std::endl;
  
}
