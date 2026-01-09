#ifndef AQUATIC_H
#define AQUATIC_H

#include "Animal.h"
#include <iostream>

class Aquatic : virtual public Animal {
protected:
    double maxDiveDepth;

    Aquatic(const std::string& name, int age, double weight, double maxDiveDepth)
        : Animal(name, age, weight), maxDiveDepth(maxDiveDepth) {
        std::cout << "Stvorena vodena zivotinja koja roni do "
            << maxDiveDepth << "m\n";
    }
};

#endif

