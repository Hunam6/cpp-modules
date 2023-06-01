#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
	: value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed &other)
{
	std::cout << "Copy constructor called\n";
	value = other.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed &Fixed::operator=(Fixed &other)
{
	std::cout << "Copy assignment operator called\n";
	value = other.getRawBits();
	return *this;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	value = raw;
}
