#ifndef SEATURTLE_H
#define SEATURTLE_H

#include "Aquatic.h"

class SeaTurtle : public Aquatic {
public:
    SeaTurtle(const std::string& name, int age, double weight)
        : Animal(name, age, weight),
        Aquatic(name, age, weight, 200.0) {
    }

    std::string getSpecies() const override {
        return "SeaTurtle";
    }

    std::string getName() const override {
        return name;
    }

    double getDailyFood() const override {
        double food = weight * 0.03;
        if (food == 0)
            throw std::logic_error("Kolicina hrane je 0");
        return food;
    }
};

#endif

