#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
	std::cout << "Animal: Default constructor called\n";
	brain = new Brain();
}

Animal::Animal(Animal &other)
{
	std::cout << "Animal: Copy constructor called\n";
	type = other.type;
	brain = new Brain(*other.brain);
}

Animal::~Animal()
{
	std::cout << "Animal: Destructor called\n";
	delete brain;
}

Animal &Animal::operator=(Animal &other)
{
	std::cout << "Animal: = operator called\n";
	type = other.type;
	brain = other.brain;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "*Generic animal sound*\n";
}

std::string Animal::getType() const
{
	return type;
}

Brain *Animal::getBrain()
{
	return brain;
}
