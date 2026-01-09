#ifndef LION_H
#define LION_H

#include "Mammal.h"

class Lion : public Mammal {
public:
    Lion(const std::string& name, int age, double weight)
        : Animal(name, age, weight),
        Mammal(name, age, weight, true) {
    }

    std::string getSpecies() const override {
        return "Lion";
    }

    std::string getName() const override {
        return name;
    }

    double getDailyFood() const override {
        double food = weight * 0.06;
        if (food == 0)
            throw std::logic_error("Kolicina hrane je 0");
        return food;
    }
};

#endif

