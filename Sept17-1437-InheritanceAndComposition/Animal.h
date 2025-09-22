#pragma once
#include <string>

//class Animal
//{
//	std::string name; 
//
//	int height; 
//};
//
//class Building : public Animal //A building is NOT a type of animal - don't do this!
//{
//	std::string cityInWhichBuildingIsLocated; 
//};

class Animal
{
private: //private access specifier "abstracts" away complexity (of understanding) 
	int height{};

	std::string m_speciesName{};
	int numberOfLegs{};
protected:
	double mass{}; //in pounds

public:
	/*Note the initialization in the constructor definition -> most common? number of legs for an animal is 4 (maybe)*/
	Animal(const int height, const double mass, int numberOfLegs = 4, const std::string& name = "TBD");

	void printAnimalAttributes();

	void eat(); 
};

enum class FurinessLevel
{
	NotAtAllFurry = 0,
	MildlyFurry = 1,
	ModeratelyFurry = 2,
	VeryFurryDog = 3
};


class Dog : public Animal
{
private:
	std::string familiarName;
	FurinessLevel furriness;
	int tailLength{};

public:
	Dog(const int height, const double mass, int numberOfLegs, const std::string& name,
		const std::string& familiarName, FurinessLevel furriness, const int tailLength);

	void printDogAttributes();

	/*play a sound file*/
	void bark();

	/*We would LIKE this function to OVERRIDE the parent's eat method (Animal::eat())*/
	void eat(); 
};

/*Added after lecture*/
class Cat : public Animal
{
	double concentrationOfAllergenFELD1{}; 

public: 
	/*Shows video of cat making strange "gesture"*/
	void doWeirdButCuteThing(); 

	/*plays audio file*/
	void purr();
};