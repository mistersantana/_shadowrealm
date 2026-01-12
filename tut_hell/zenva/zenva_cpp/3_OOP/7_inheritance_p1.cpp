#include <iostream>
#include <string>

class GameCharacter
{
  public:
    static std::string type;

    std::string name;
    // int maxHealth; // move property to Player
    int currentHealth;
    int damage;
    bool isAlive;

    GameCharacter(std::string, int, int); // remove maxHealth from constructor
    void takeDamage(int);
    // void heal(int); // move method to Player

    static void printType();
};

GameCharacter::GameCharacter(std::string _name, int _currentHealth, int _damage)
{
  name = _name;
  // maxHealth = _maxHeath;
  currentHealth = _currentHealth;
  damage = _damage;
  isAlive = true;
}

std::string GameCharacter::type = "Non player character";

void GameCharacter::takeDamage(int amount)
{
  currentHealth -= amount;
  if (currentHealth <= 0)
  {
    currentHealth = 0;
    isAlive = false;
  }
}

void GameCharacter::printType()
{
  std::cout << "Game character has the type of " << type << std::endl;
}

// create a Player Character subclass
class Player: public GameCharacter
{
  public:
    int maxHealth;

    Player(std::string, int, int, int);

    void heal(int);
};

// constructor of the Player class
Player::Player(std::string _name, int _currentHealth, int _maxHealth, int _damage): GameCharacter(_name, _currentHealth, _damage)
{
  maxHealth = _maxHealth;
}

// heal method now beongs to the Player class
void Player::heal(int amount)
{
  currentHealth += amount;
  if (currentHealth > maxHealth)
  {
    currentHealth = maxHealth;
  }
}

int main()
{
  // create a Player instance
  Player player = Player("Player", 120, 150, 20);
  std::cout << player.name << std::endl;
}
