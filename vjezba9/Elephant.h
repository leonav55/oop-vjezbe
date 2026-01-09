#ifndef ELEPHANT_H
#define ELEPHANT_H

#include "Mammal.h"

class Elephant : public Mammal {
public:
    Elephant(const std::string& name, int age, double weight)
        : Animal(name, age, weight),
        Mammal(name, age, weight, false) {
    }

    std::string getSpecies() const override {
        return "Elephant";
    }

    std::string getName() const override {
        return name;
    }

    double getDailyFood() const override {
        double food = weight * 0.04;
        if (food == 0)
            throw std::logic_error("Kolicina hrane je 0");
        return food;
    }
};

#endif

