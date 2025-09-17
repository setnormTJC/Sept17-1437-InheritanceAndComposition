#pragma once
#include <string>
class Animal
{
private: //private access specifier "abstracts" away complexity (of understanding) 
	int height{};

	std::string m_speciesName{};
protected:
	double mass{}; //in pounds

public:
	Animal(const int height, const double mass, const std::string& name);

	void printAnimalAttributes();
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
	Dog(const int height, const double mass, const std::string& name,
		const std::string& familiarName, FurinessLevel furriness, const int tailLength);

	void printDogAttributes();

	/*play a sound file*/
	void bark();
};