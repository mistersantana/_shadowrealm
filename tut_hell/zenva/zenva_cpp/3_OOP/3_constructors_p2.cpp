#include <iostream>

class GameCharacter {
  public:
    std::string name;
    int maxHealth;
    int currentHealth;
    int damage;

    // create a constructor
    GameCharacter(std::string, int, int, int); // this is a function signature

    // create another constructor
    GameCharacter(std::string, int, int);
};

// implement the constructor
GameCharacter::GameCharacter(std::string _name, int _maxHealth, int _currentHealth, int _damage) {
  // set the values
  name = _name;
  maxHealth = _maxHealth;
  currentHealth = _currentHealth;
  damage = _damage;
}

// implement the second constructor
// GameCharacter::GameCharacter(std::string _name, int _health, int _damage) {
//   //set the values
//   name = _name;
//   maxHealth = _health;
//   currentHealth = _health;
//   damage = _damage;
// }

// take the field assignment out of the function body for the second constructor
GameCharacter::GameCharacter(std::string _name, int _health, int _damage): name(_name), maxHealth(_health), currentHealth(_health), damage(_damage) { }

int main() {

  // use the first constructor to create an instance of GameCharacter
  GameCharacter character1 = GameCharacter("Nimish", 100, 100, 10);
  std::cout << character1.name << std::endl;

  // use the second constructor to create an instance of GameCharacter
  GameCharacter character2 = GameCharacter("Zenva", 150, 20);
  std::cout << character2.maxHealth << std::endl;

  // we can also create instances via short-form syntax
  // GameCharacter character3 ("Zenva", 150, 20);
  // GameCharacter character4 = "Zenva", 150, 20;
  // GameCharacter character5 {"Zenva", 150, 20};
  // GameCharacter character6 = {"Zenva", 150, 20};

}
