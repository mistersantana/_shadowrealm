#include <iostream>

// a function with a return type of string
std::string getFullName(std::string first, std::string last){

  std::string fullName = first + " " + last;
  return fullName; // output a value
}

int main() {
  
std::string fullName = getFullName("Nimmish", "Narang");
std::cout << fullName << std::endl;

//function signature
// std::string getfullName

//function signature
// std::string getFullName(std::string, std::string);
}
