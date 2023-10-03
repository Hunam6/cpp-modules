#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal *animal = new Animal();
	const Animal *cat = new Cat();
	const Animal *dog = new Dog();
	std::cout << animal->getType() << "\n";
	std::cout << cat->getType() << "\n";
	std::cout << dog->getType() << "\n";
	animal->makeSound();
	cat->makeSound();
	dog->makeSound();
	delete animal;
	delete dog;
	delete cat;

	const WrongAnimal *wrongAnimal = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();
	std::cout << wrongAnimal->getType() << "\n";
	std::cout << wrongCat->getType() << "\n";
	wrongAnimal->makeSound();
	wrongCat->makeSound();
	delete wrongAnimal;
	delete wrongCat;

	const WrongCat *otherWrongCat = new WrongCat();
	otherWrongCat->makeSound();
	delete otherWrongCat;
}
