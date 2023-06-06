#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	std::cout << "Cat: Default constructor called\n";
	type = "Cat";
}

Cat::Cat(Cat &other)
{
	std::cout << "Cat: Copy constructor called\n";
	type = other.type;
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor called\n";
	type = "Cat";
}

Cat &Cat::operator=(Cat &other)
{
	std::cout << "Cat: = operator called\n";
	type = other.type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "miaou miaou\n";
}
