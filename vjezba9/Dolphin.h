#ifndef DOLPHIN_H
#define DOLPHIN_H

#include "Mammal.h"
#include "Aquatic.h"

class Dolphin : public Mammal, public Aquatic {
public:
    Dolphin(const std::string& name, int age, double weight)
        : Animal(name, age, weight),
        Mammal(name, age, weight, true),
        Aquatic(name, age, weight, 300.0) {
    }

    std::string getSpecies() const override {
        return "Dolphin";
    }

    std::string getName() const override {
        return name;
    }

    double getDailyFood() const override {
        double food = weight * 0.05;
        if (food == 0)
            throw std::logic_error("Kolicina hrane je 0");
        return food;
    }
};

#endif

