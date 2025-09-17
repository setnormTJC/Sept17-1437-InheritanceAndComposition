#include "Animal.h"
#include <iostream>
#include <iomanip>

Animal::Animal(const int height, const double mass, int numberOfLegs, const std::string& name)
    :height(height), mass(mass), numberOfLegs(numberOfLegs), m_speciesName(name)
{

}

void Animal::printAnimalAttributes()
{
    std::cout << std::setw(15) << height;
    std::cout << std::setw(15) << mass; //NOTE: Animal::mass ACTUALLY suggests a "static" member 
    std::cout << std::setw(15) << numberOfLegs;
    std::cout << std::setw(25) << m_speciesName;
    std::cout << "\n";
}

Dog::Dog(const int height, const double mass, int numberOfLegs, const std::string& name,
    const std::string& familiarName, FurinessLevel furriness, const int tailLength)
    :Animal(height, mass, numberOfLegs, name), //calls parent class constructor (Java uses "super()" here)
    familiarName(familiarName), furriness(furriness),tailLength(tailLength)
{
    //still empty!
}

void Dog::printDogAttributes()
{
    Animal::printAnimalAttributes();
    
    std::cout << "\nAdditional attributes of the dog animal (familiar name, furriness (as an integer), and tail length(inches): \n";
    
    constexpr int FURRY_COL_WIDTH = 5;

    std::cout << std::setw(15) << familiarName;
    std::cout << std::setw(FURRY_COL_WIDTH) << (int)furriness;
    std::cout << std::setw(5) << tailLength;

    //std::cout << std::setw(15) << Animal::mass;
    //this IS allowed because mass was set to "protected"

}
