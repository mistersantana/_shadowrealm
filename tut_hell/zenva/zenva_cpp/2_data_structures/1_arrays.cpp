#include <iostream>

int main() {

  // an array would have the name followed by square brackets
  std::string roster[] = {"Nimish", "Sally", "John"}; // an array of string elements

  // we can have any type of array we want
  int number[] = {1, 5}; // an integer array

  /* if you know the size of the array but not the initial values, the array can be declared with the number of elements */
  std::string names[3]; // array have a static length

  // retrieving an element from an array using its index
  std::string firstMember = roster[0]; // indexing is 0-based
  std::cout << firstMember << std::endl;

  // modifying an array element using its index
  roster[1] = "Jane";
  std::cout << roster[1] << std::endl;


  // CHALLENGE ---------------------------------------------------------------
  // Add another member to the 'roster' array
  // Hint: As arrays have a static length, you cannot add or remove elements from them. You can create a new array for the new roster and transfer the previous members using a 'for' loop.

  // solution

  std::string secondRoster[4];

  for (int i = 0; i < 3; i++) {
    // assign each member from the previous array into the new array based on the index
    secondRoster[i] = roster[i];
  }
  secondRoster[3] = "Sally"; // assign the final member
}
