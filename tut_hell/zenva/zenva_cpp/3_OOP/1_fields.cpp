#include <iostream>

// classes are creaeted outside the main function

// modelling a game character
class GameCharacter {
  public: // for access controll
    // define properties
    std::string name;
    int health;
    int damage;
} character1; // create an instance of class GameCharacter

int main() {

  // assign values to properties of an instance
  character1.name = "Nimish";
  character1.health = 100;
  character1.damage = 10;

  // access the values of the properties
  std::cout << character1.name << std::endl;

  // create a new instance of the GameCharacter class
  GameCharacter character2;
  character2.name = "Zenva";
  character2.health = 150;
  character2.damage = 20;

  std::cout << character2.name << std::endl;
  
}
