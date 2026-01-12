#include <iostream>

class GameCharacter {
  public:
    std::string name;
    int maxHealth;
    int currentHealth;
    int damage;
    bool isAlive;

    GameCharacter(std::string, int, int, int);
    void takeDamage(int);
    void heal(int);
};

GameCharacter::GameCharacter(std::string _name, int _maxHealth, int _currentHealth, int _damage) {
  name = _name;
  maxHealth = _maxHealth;
  currentHealth = _currentHealth;
  damage = _damage;
  isAlive = true;
}

void GameCharacter::takeDamage(int amount) {
  currentHealth -= amount;

  if (currentHealth <= 0) {
    currentHealth = 0;
    isAlive = false;
  }
}

void GameCharacter::heal(int amount) {
  currentHealth += amount;

  if (currentHealth > maxHealth) {
    currentHealth = maxHealth;
  }
}

// NEW: method implementation for a GameCharacter to attack another
void attack(GameCharacter *attacker, GameCharacter *defender) {
  int damage = attacker->damage; // retrieve the damage
  defender->takeDamage(damage); // take the damage
}

int main() {

  GameCharacter character1 = GameCharacter("Nimish", 100, 100, 10);

  // create a GameCharacter pointer
  GameCharacter *characterPtr = &character1; // has to point to an instance

  // use the pointer to modify parameter values
  characterPtr->damage = 15;
  std::cout << character1.damage << std::endl;

  // use the pointer to change properties with methods
  characterPtr->takeDamage(20);
  std::cout << character1.currentHealth << std::endl;

  GameCharacter character2 = GameCharacter("Zenva", 150, 150, 20);

  // pass in addresses to call attack method
  attack(&character2, &character1);
  std::cout << character1.currentHealth << std::endl;
  
}
