#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal: Default constructor called\n";
}

WrongAnimal::WrongAnimal(WrongAnimal &other)
{
	std::cout << "WrongAnimal: Copy constructor called\n";
	type = other.type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: Destructor called\n";
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &other)
{
	std::cout << "WrongAnimal: = operator called\n";
	type = other.type;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "*Generic wrong animal sound*\n";
}

std::string WrongAnimal::getType() const
{
	return type;
}
