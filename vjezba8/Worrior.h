#ifndef WARRIOR_H
#define WARRIOR_H
#include "Player.h"


class Warrior : public Player {
bool shieldActive;


public:
Warrior(const std::string& name);
void attackEnemy(Enemy* target) override;
void specialAbility() override;
void displayStatus() const override;
void takeDamage(int amount);
};
#endif
