#include<iostream>

int main(){

  // compile time error
  // std::cout << "This is a compile time error." << std::endl

  // run time error + warning
  int value = 7 / 0;
  std::cout << "value : " << value << std::endl;

  return 0;
}
