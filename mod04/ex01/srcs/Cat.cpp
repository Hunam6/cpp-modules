#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	std::cout << "Cat: Default constructor called\n";
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(Cat &other)
	: Animal(other)
{
	std::cout << "Cat: Copy constructor called\n";
	brain = new Brain(*other.brain);
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor called\n";
	delete brain;
}

Cat &Cat::operator=(Cat &other)
{
	Animal::operator=(other);
	std::cout << "Cat: = operator called\n";
	brain = new Brain(*other.brain);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "miaou miaou\n";
}

Brain *Cat::getBrain() const
{
	return brain;
}
