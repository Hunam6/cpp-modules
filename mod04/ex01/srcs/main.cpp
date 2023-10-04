#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
	Animal *animals[10];

	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	Cat *firstCat = dynamic_cast<Cat *>(animals[0]);
	firstCat->getBrain()->addIdea("crazy idea");
	std::cout << "fist cat, first idea: "
			  << firstCat->getBrain()->getIdea(0) << "\n";

	Cat deepCopyCat(dynamic_cast<Cat &>(*animals[0]));
	std::cout << "deepCopyCat, first idea: "
			  << deepCopyCat.getBrain()->getIdea(0) << "\n";

	deepCopyCat.getBrain()->addIdea("bad idea");
	std::cout << "deepCopyCat, second idea: "
			  << deepCopyCat.getBrain()->getIdea(1) << "\n";
	std::cout << "firstCat, second idea: "
			  << firstCat->getBrain()->getIdea(1) << "(should be nothing)\n";

	for (int i = 0; i < 10; i++)
		delete animals[i];
}
