#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int rawBits;
	static const int fractionalBitsNb = 8;

public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();
	Fixed &operator=(const Fixed &other);
	int getRawBits() const;
	void setRawBits(int const rawBits);
	float toFloat() const;
	int toInt() const;
};

std::ostream &operator<<(std::ostream &stream, const Fixed &fixed);

#endif
