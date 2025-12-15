#include "GameCharacter.h"


GameCharacter::GameCharacter(const std::string& name, int health)
: name(name), health(health), maxHealth(health) {}


GameCharacter::~GameCharacter() {}


void GameCharacter::takeDamage(int amount) {
health -= amount;
if (health < 0) health = 0;
}


bool GameCharacter::isAlive() const {
return health > 0;
}


const std::string& GameCharacter::getName() const { return name; }
int GameCharacter::getHealth() const { return health; }
