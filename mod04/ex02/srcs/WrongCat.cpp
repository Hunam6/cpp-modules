#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
	std::cout << "WrongCat: Default constructor called\n";
	type = "WrongCat";
}

WrongCat::WrongCat(WrongCat &other)
{
	std::cout << "WrongCat: Copy constructor called\n";
	type = other.type;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Destructor called\n";
	type = "WrongCat";
}

WrongCat &WrongCat::operator=(WrongCat &other)
{
	std::cout << "WrongCat: = operator called\n";
	type = other.type;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "miaou miaou but in a weird way\n";
}
