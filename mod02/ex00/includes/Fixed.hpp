#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
	int rawBits;
	static const int fractionalBitsNb = 8;

public:
	Fixed();
	Fixed(Fixed &other);
	~Fixed();
	Fixed &operator=(Fixed &other);
	int getRawBits() const;
	void setRawBits(const int rawBits);
};

#endif
