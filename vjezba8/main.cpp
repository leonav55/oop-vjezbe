#include <vector>
#include <algorithm>
#include "Warrior.h"
#include "Mage.h"
#include "Gnome.h"
#include "Boss.h"


int main() {
std::vector<GameCharacter*> characters;


Warrior* conan = new Warrior("Conan");
Mage* merlin = new Mage("Merlin");
Gnome* gnomeo = new Gnome("Gnomeo");
Gnome* sneaky = new Gnome("Sneaky");
Boss* dragon = new Boss("Dragon");


characters = {conan, merlin, gnomeo, sneaky, dragon};


conan->attackEnemy(gnomeo); gnomeo->displayStatus(); conan->displayStatus();
merlin->attackEnemy(sneaky); sneaky->displayStatus(); merlin->displayStatus();
gnomeo->attackPlayer(conan); conan->displayStatus(); gnomeo->displayStatus();
merlin->attackEnemy(gnomeo); gnomeo->displayStatus(); merlin->displayStatus();
dragon->attackPlayer(merlin); merlin->displayStatus(); dragon->displayStatus();
merlin->attackEnemy(gnomeo);
conan->attackEnemy(dragon);
merlin->attackEnemy(dragon);


std::cout << "\n--- Special abilities ---\n";
for (auto c : characters) c->specialAbility();


GameCharacter* healthiest = nullptr;
for (auto c : characters) {
if (c->isAlive()) {
c->displayStatus();
if (!healthiest || c->getHealth() > healthiest->getHealth())
healthiest = c;
}
}


if (healthiest)
std::cout << "\nMost health: " << healthiest->getName() << std::endl;


for (auto c : characters) delete c;
}
