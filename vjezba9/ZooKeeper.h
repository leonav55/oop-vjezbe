#ifndef ZOOKEEPER_H
#define ZOOKEEPER_H

#include "Animal.h"
#include <iostream>

class ZooKeeper {
private:
    static int totalAnimalsServed;

public:
    void processAnimal(Animal* animal) {
        std::cout << "Species: " << animal->getSpecies()
            << ", Name: " << animal->getName()
            << ", Food: " << animal->getDailyFood() << "kg\n";
        totalAnimalsServed++;
    }

    static int getTotalAnimalsServed() {
        return totalAnimalsServed;
    }
};

int ZooKeeper::totalAnimalsServed = 0;

#endif

