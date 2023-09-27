#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
	: rawBits(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called\n";

	rawBits = other.rawBits;
}

Fixed::Fixed(const int value)
	: rawBits(value << fractionalBitsNb)
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float value)
	: rawBits(std::roundf(value * (1 << fractionalBitsNb)))
{
	std::cout << "Float constructor called\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called\n";

	rawBits = other.rawBits;
	return *this;
}

std::ostream &operator<<(std::ostream &stream, const Fixed &fixed)
{
	stream << fixed.toFloat();
	return stream;
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

float Fixed::toFloat() const
{
	return (static_cast<float>(rawBits) / (1 << fractionalBitsNb));
}

int Fixed::toInt() const
{
	return rawBits >> fractionalBitsNb;
}
