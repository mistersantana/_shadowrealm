#include<iostream>

int main(){

  std::string name = "Nimish";

  // size function - size()
  // to get the length of the string
  std::cout << name.size() << std::endl;

  // empty function - empty()
  // to determine whether or not, the string is empty
  std::cout << name.empty() << std::endl;

  // substring function - substr(index, length)
  // to retrieve a part of a string
  std::cout << name.substr(0,3) << std::endl;

  // append function - append(string)
  // to add a string to the end of another
  name.append(" Narang");
  std::cout << name << std::endl;

  // insert function - insert(index, string)
  // to insert a string at a specified index
  name = "Nimesh";
  name.insert(3, "i");
  std::cout << name << std::endl;

  // erase function - erase(index, length)
  // to erase a string of a certain length at a specified index
  name.erase(4,1);
  std::cout << name << std::endl;

}
