#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	std::cout << "Cat: Default constructor called\n";
	type = "Cat";
}

Cat::Cat(Cat &other)
	: Animal(other)
{
	std::cout << "Cat: Copy constructor called\n";
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor called\n";
}

Cat &Cat::operator=(Cat &other)
{
	Animal::operator=(other);
	std::cout << "Cat: = operator called\n";
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "miaou miaou\n";
}
