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
	animals[0]->getBrain()->ideas->append("crazy idea");
	std::cout << "animals[0] -> brain -> ideas[0] = "
			  << animals[0]->getBrain()->ideas[0] << "\n";

	Cat deepCopyCat(dynamic_cast<Cat &>(*animals[0]));
	std::cout << "deepCopyCat -> brain -> ideas[0] = "
			  << deepCopyCat.getBrain()->ideas[0] << "\n";

	for (int i = 0; i < 10; i++)
		delete animals[i];
}
