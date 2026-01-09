#include <iostream>
#include <memory>

#include "Lion.h"
#include "Elephant.h"
#include "Dolphin.h"
#include "SeeTurtle.h"
#include "ZooSection.h"
#include "ZooKeeper.h"

int main() {
    try {
        ZooSection<Animal> zoo;
        ZooKeeper keeper;

        zoo.addAnimal(std::make_unique<Lion>("Simba", 5, 190));
        zoo.addAnimal(std::make_unique<Elephant>("Dumbo", 10, 1200));
        zoo.addAnimal(std::make_unique<Dolphin>("Flipper", 7, 150));
        zoo.addAnimal(std::make_unique<SeaTurtle>("Shelly", 50, 80));

        for (size_t i = 0; i < zoo.size(); i++) {
            keeper.processAnimal(zoo.getAnimal(i));
        }

        std::cout << "\nUkupna dnevna hrana: "
            << zoo.totalFood() << "kg\n";
        std::cout << "Ukupno nahranjenih zivotinja: "
            << ZooKeeper::getTotalAnimalsServed() << "\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Greska: " << e.what() << "\n";
    }

    return 0;
}
