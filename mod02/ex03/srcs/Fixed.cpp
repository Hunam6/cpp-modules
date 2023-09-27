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

bool Fixed::operator>(const Fixed &other) const
{
	return toFloat() > other.toFloat();
}

bool Fixed::operator<(const Fixed &other) const
{
	return toFloat() < other.toFloat();
}

bool Fixed::operator>=(const Fixed &other) const
{
	return toFloat() >= other.toFloat();
}

bool Fixed::operator<=(const Fixed &other) const
{
	return toFloat() <= other.toFloat();
}

bool Fixed::operator==(const Fixed &other) const
{
	return rawBits == other.rawBits;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return rawBits != other.rawBits;
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return Fixed(toFloat() / other.toFloat());
}

Fixed &Fixed::operator++()
{
	++rawBits;
	return *this;
}

Fixed &Fixed::operator--()
{
	--rawBits;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed fixed(*this);
	++rawBits;
	return fixed;
}

Fixed Fixed::operator--(int)
{
	Fixed fixed(*this);
	--rawBits;
	return fixed;
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

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}
