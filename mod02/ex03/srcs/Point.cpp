#include "Point.hpp"

Point &Point::operator=(const Point &other)
{
	(void)other;
	return *this;
}

const Fixed &Point::X() const
{
	return x;
}

const Fixed &Point::Y() const
{
	return y;
}
