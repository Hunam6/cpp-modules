#include "Point.hpp"

Point::Point()
	: x(0), y(0) {}

Point::Point(float x, float y)
	: x(x), y(y) {}

Point::Point(const Point &other)
	: x(other.x), y(other.y) {}

Point::~Point() {}

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
