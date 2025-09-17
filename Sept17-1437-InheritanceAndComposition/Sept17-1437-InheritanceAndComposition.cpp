// Sept17-1437-InheritanceANDComposition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iomanip>
#include <iostream>

#include "Animal.h"

int main()
{
    Animal someAnimal(32, 51.2, "animal name"); //31 lbs, 51.2 inches
    std::cout << std::setw(15) << "Height(inches)";
    std::cout << std::setw(15) << "Mass(pounds)";
    std::cout << std::setw(15) << "Name";
    std::cout << "\n";

    someAnimal.printAnimalAttributes();
    //std::cout << "Hello World!\n";

    //Thelma the dog's attributes: 20 lbs, height is about 16 inches, mildly furry, 
    //species name is canis familiaris,11 inch long tail 
    Dog myDog(16, 20, "canis familiaris", "Thelma (Noodle)", FurinessLevel::MildlyFurry, 11);

    myDog.printDogAttributes();
}

