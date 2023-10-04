#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "Dog: Default constructor called\n";
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(Dog &other)
	: Animal(other)
{
	std::cout << "Dog: Copy constructor called\n";
	brain = new Brain(*other.brain);
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor called\n";
	delete brain;
}

Dog &Dog::operator=(Dog &other)
{
	Animal::operator=(other);
	std::cout << "Dog: = operator called\n";
	brain = new Brain(*other.brain);
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "waf waf\n";
}

Brain *Dog::getBrain() const
{
	return brain;
}
