#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H


#include <string>
#include <iostream>


class GameCharacter {
protected:
std::string name;
int health;
int maxHealth;


public:
GameCharacter(const std::string& name, int health);
virtual ~GameCharacter();


virtual void displayStatus() const = 0;
virtual void specialAbility() = 0;


void takeDamage(int amount);
bool isAlive() const;


const std::string& getName() const;
int getHealth() const;
};


#endif
