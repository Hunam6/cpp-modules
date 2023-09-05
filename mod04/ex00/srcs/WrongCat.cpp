#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
	std::cout << "WrongCat: Default constructor called\n";
	type = "WrongCat";
}

WrongCat::WrongCat(WrongCat &other)
	: WrongAnimal(other)
{
	std::cout << "WrongCat: Copy constructor called\n";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Destructor called\n";
}

WrongCat &WrongCat::operator=(WrongCat &other)
{
	WrongAnimal::operator=(other);
	std::cout << "WrongCat: = operator called\n";
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "miaou miaou but in a wrong way\n";
}
