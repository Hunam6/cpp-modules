#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
	std::cout << "Animal: Default constructor called\n";
}

Animal::Animal(Animal &other)
{
	std::cout << "Animal: Copy constructor called\n";
	type = other.type;
}

Animal::~Animal()
{
	std::cout << "Animal: Destructor called\n";
}

Animal &Animal::operator=(Animal &other)
{
	std::cout << "Animal: = operator called\n";
	type = other.type;
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
