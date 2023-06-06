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
	animals[2]->getBrain()->ideas->append("crazy idea");
	std::cout << "animals[2][0] = " << animals[2]->getBrain()->ideas[0] << "\n";
	animals[2]->makeSound();

	Cat *deepCopy = new Cat(*static_cast<Cat *>(animals[2]));
	std::cout << "deepCopy[0] = " << deepCopy->getBrain()->ideas[0] << "(should be empty)\n";
	delete deepCopy;

	for (int i = 0; i < 10; i++)
		delete animals[i];
}
