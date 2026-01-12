#include <iostream>

// function to increase an integer value by one
void increase(int *i) {
  (*i)++; // dereference i and increment the value
}

int main() {

  // assigning an int to another int
  int age = 28;
  int newAge = age;

  std::cout << age << std::endl;
  std::cout << newAge << std::endl;

  /* by using a pointer, we can change the value or the variable and both will always present the most up to date value */
  age = 30;
  int *agePtr = &age;
  
  std::cout << age << std::endl;
  std::cout << *agePtr << std::endl; // dereferencing the pointer

  // if the variable value is changed now, the dereferenced value also changes
  age = 31;

  std::cout << age << std::endl;
  std::cout << *agePtr << std::endl;

  // if the dereferenced pointer value is changed, the variable value will also change
  (*agePtr) = 32;

  std::cout << age << std::endl;
  std::cout << *agePtr << std::endl;

  /* this logic can be applied to functions as well, and used to change a variable value outside of a function */
  increase(&age); // pass the reference to age
  
  std::cout << age << std::endl;
  std::cout << *agePtr << std::endl;

  /* nullify a pointer afterwards to make sure that it is no longer referring to a memory that might not be there */
  agePtr = NULL;

}
