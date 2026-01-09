#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <stdexcept>

class Animal {
protected:
    std::string name;
    int age;
    double weight;

    Animal(const std::string& name, int age, double weight) {
        if (name.empty())
            throw std::invalid_argument("Ime ne smije biti prazno");
        if (age < 0)
            throw std::invalid_argument("Godine ne smiju biti negativne");
        if (weight <= 0)
            throw std::invalid_argument("Tezina mora biti veca od 0");

        this->name = name;
        this->age = age;
        this->weight = weight;
    }

public:
    virtual ~Animal() = default;

    virtual std::string getSpecies() const = 0;
    virtual double getDailyFood() const = 0;
    virtual std::string getName() const = 0;
};

#endif

