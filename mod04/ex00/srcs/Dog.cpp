#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "Dog: Default constructor called\n";
	type = "Dog";
}

Dog::Dog(Dog &other)
{
	std::cout << "Dog: Copy constructor called\n";
	type = other.type;
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor called\n";
	type = "Dog";
}

Dog &Dog::operator=(Dog &other)
{
	std::cout << "Dog: = operator called\n";
	type = other.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "waf waf\n";
}
