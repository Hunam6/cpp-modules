#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "Dog: Default constructor called\n";
	type = "Dog";
}

Dog::Dog(Dog &other)
	: Animal(other)
{
	std::cout << "Dog: Copy constructor called\n";
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor called\n";
}

Dog &Dog::operator=(Dog &other)
{
	Animal::operator=(other);
	std::cout << "Dog: = operator called\n";
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "waf waf\n";
}
