#include "Boss.h"
#include "Player.h"


Boss::Boss(const std::string& name)
: Enemy(name, 300, 8) {}


void Boss::attackPlayer(Player* target) {
if (!target || !target->isAlive()) return;
target->takeDamage(10 * difficulty);
}


void Boss::specialAbility() {
health += 50;
if (health > maxHealth) health = maxHealth;
std::cout << name << " regenerates health!" << std::endl;
}


void Boss::displayStatus() const {
std::cout << "Boss " << name << " | HP: " << health << std::endl;
}
