#include <iostream>

int main() {

  // firsg specify the name of the type we want to rename, then the name to which we want to change the type.
  // ex: renaming int * type to intPtr
  typedef int *intPtr;

  // we can then use intPtr in place of int * at any point
  int i = 5;
  int *ptr = &i; // original syntax
  std::cout << *ptr << std::endl;
  intPtr altPtr = &i; // alternative way of using the new intPtr type
  std::cout << *altPtr << std::endl;

  // we can do the same thing using the 'using' keyword, in a different order
  // renaming char * to chatPr
  using charPtr = char *;
  char a = 'a';
  charPtr aPtr = &a;
  std::cout << aPtr << std::endl;
}
