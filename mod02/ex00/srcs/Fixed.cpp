#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
	: rawBits(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed &other)
{
	std::cout << "Copy constructor called\n";
	rawBits = other.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed &Fixed::operator=(Fixed &other)
{
	std::cout << "Copy assignment operator called\n";
	rawBits = other.getRawBits();
	return *this;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return rawBits;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	rawBits = raw;
}
