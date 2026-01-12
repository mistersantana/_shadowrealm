#include <iostream>

int main() {

  // logical operators
  // ! && ||

  // the NOT operator
  bool isGameOver = false;
  bool isNotGameOver = !isGameOver; // get the reverse of a boolean
  std::cout << isGameOver << std::endl;
  std::cout << isNotGameOver << std::endl;

  // the AND operator
  int health = 0;
  int lives = 0;
  isGameOver = health <= 0 && lives <= 0; // condition1 AND condition2
  std::cout << isGameOver << std::endl;

  // the OR operator
  health = 0;
  isGameOver = health <= 0 || lives <= 0; // condition1 OR condition2
  std::cout << isGameOver << std::endl;


  // CHALLENGE --------------------------------------------------------------

  bool result;

  // 1. What is the result?
  int a = 1;
  result = a - 1 != 0;

  // solution
  std::cout << result << std::endl; // false

  // 2. What is the result?
  std::string y = "y";
  std::string x = "x";
  result = !(x > y);

  // solution
  std::cout << result << std:: endl; // true

  // 3. What is the result?
  bool hasKey = true;
  bool isDoorLocked = true;
  int movementPoints = 1;
  result = (hasKey || !isDoorLocked) && movementPoints > 0;

  // solution
  std::cout << result << std::endl; // true

}
