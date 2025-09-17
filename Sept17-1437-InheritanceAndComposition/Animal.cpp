#include "Animal.h"
#include <iostream>
#include <iomanip>

Animal::Animal(const int height, const double mass, const std::string& name)
    :height(height), mass(mass), m_speciesName(name)
{
    //this->name = name; 
}

void Animal::printAnimalAttributes()
{
    std::cout << std::setw(15) << height;
    std::cout << std::setw(15) << Animal::mass;
    std::cout << std::setw(15) << Animal::m_speciesName;
    std::cout << "\n";
}

Dog::Dog(const int height, const double mass, const std::string& name,
    const std::string& familiarName, FurinessLevel furriness, const int tailLength)
    :Animal(height, mass, name), familiarName(familiarName), furriness(furriness),
    tailLength(tailLength)
{
    //still empty!
}

void Dog::printDogAttributes()
{
    Animal::printAnimalAttributes();
    constexpr int FURRY_COL_WIDTH = 5;

    std::cout << std::setw(15) << Dog::familiarName;
    std::cout << std::setw(FURRY_COL_WIDTH) << (int)Dog::furriness;
    std::cout << std::setw(5) << Dog::tailLength;

    //std::cout << std::setw(15) << Animal::mass;
    //this IS allowed because mass was set to "protected"

}
