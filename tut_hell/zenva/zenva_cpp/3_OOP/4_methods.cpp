#include <iostream>

class GameCharacter {
  public:
    std::string name;
    int maxHealth;
    int currentHealth;
    int damage;
    bool isAlive; // NEW: variable to check if character is alive

    GameCharacter(std::string, int, int, int);
    void takeDamage(int); // NEW: method signature for taking damage
    void heal(int); // NEW: method signature for healing
};

GameCharacter::GameCharacter(std::string _name, int _maxHealth, int _currentHealth, int _damage) {
  name = _name;
  maxHealth = _maxHealth;
  currentHealth = _currentHealth;
  damage = _damage;
  isAlive = true; // NEW: character is alive at creation of the instance
}

// NEW: implementation of the takeDamage method
void GameCharacter::takeDamage(int amount) {
  currentHealth -= amount; // deduct damage from current health amount
  if (currentHealth <= 0) {
    currentHealth = 0; // ensure health is never less than zero
    isAlive = false; // character is dead
  }
}

// NEW: implementation of the heal method
void GameCharacter::heal(int amount) {
  currentHealth += amount; // add health to current health
  if (currentHealth > maxHealth) {
    currentHealth = maxHealth; // ensure health doesn't exceed max health amount
  }
}


int main() {

	GameCharacter character1 = GameCharacter("Nimish", 100, 100, 10);

	std::cout << character1.currentHealth << std::endl;
	std::cout << character1.isAlive << std::endl;

	// call the takeDamage method on the character
	character1.takeDamage(20);

	std::cout << character1.currentHealth << std::endl;
	std::cout << character1.isAlive << std::endl;

	// call the heal method on the character
	character1.heal(30);

	std::cout << character1.currentHealth << std::endl;

}
