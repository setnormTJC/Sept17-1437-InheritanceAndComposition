// Sept17-1437-InheritanceANDComposition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iomanip>
#include <iostream>

#include "Animal.h"

int main()
{

    Animal someAnimal(32, 51.2, 2, "some Latin animal name"); //31 lbs, 51.2 inches high

    Animal someOTHERAnimal(123, 45.67);
    //NOTE! 4 legs (and speciesName) is omitted! (optional)

    std::cout << std::setw(15) << "Height(inches)";
    std::cout << std::setw(15) << "Mass(pounds)";
    std::cout << std::setw(15) << "Leg count";
    std::cout << std::setw(25) << "Species name";
    std::cout << "\n";
    //make a row of = sign for a "table header row separator"
    // std::cout << std::setfill('=')<< std::setw(15 + 15 + 15 + 25);
    // std::cout << "\n";
    // std::cout << std::setfill(' '); //reset the fill character to space
    std::cout << std::string(15 + 15 + 15 + 20, '=') << "\n";

    someAnimal.printAnimalAttributes();
    someOTHERAnimal.printAnimalAttributes(); 

    //Thelma the dog's (approximate) attributes: 20 lbs, height is about 16 inches, mildly furry, 
    //species name is canis familiaris,11 inch long tail 
    //and she has THREE legs (not 4)
    Dog myDog(16, 20, 3, "canis familiaris", "Thelma (Noodle)", FurinessLevel::MildlyFurry, 11);

    myDog.printDogAttributes();

    std::cout << "\n\n";

    std::system("puppyDog.jpg");
}

