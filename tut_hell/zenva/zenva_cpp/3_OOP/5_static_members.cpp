#include <iostream>
#include <string>

// a simplified class GameCharacter
class GameCharacter {
  public:
    static std::string type; // static variable for 'Non Player Character'

    std:: string name;

    GameCharacter(std::string);
    void changeName(std::string); // method signature for changing character name

    static void changeType(std::string); // static method signature for changing the type
};

GameCharacter::GameCharacter(std::string _name) {
  name = _name;
}

// assign GameCharacter type
std::string GameCharacter::type = "Non player character";

// method implementation for changing character name
void GameCharacter::changeName(std::string newName) {
  name = newName;
}

// static method implementation for changing the type
void GameCharacter::changeType(std::string newType) {
  type = newType;
}

int main() {

  GameCharacter character1 = GameCharacter("Nimish");
  std::cout << character1.name << std::endl;

  // since field and method are both instance members we can call them on the instance (character1) rather than on the class (GameCharacter)

  character1.changeName("Zenva");
  std::cout << character1.name << std::endl;

  // access the static member using dot syntax on an instance
  std::cout << character1.type << std::endl;

  // we can access the static memebers of a class even without an instance
  std::cout << GameCharacter::type << std::endl;

  // GameCharacter type will be the same for every instance of the class
  GameCharacter character2 = GameCharacter("John");
  std::cout << character2.type << std::endl;

  //if we change a static member value of any instance it will be refleced across all instances
  character2.type = "asdf";
  std::cout << character1.type << std::endl;
  std::cout << character2.type << std::endl;
  
  // use the static method to change the type
  character1.changeType("New type");
  std::cout << character1.type << std::endl;
  std::cout << character2.type << std::endl;

  // static method can change the type without an instance as well
  GameCharacter::changeType("Another type");
  std::cout << character1.type << std::endl;
  std::cout << character2.type << std::endl;

}
