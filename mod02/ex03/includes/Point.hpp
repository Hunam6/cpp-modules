#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;

public:
	Point() : x(0), y(0) {}
	Point(float newX, float newY) : x(newX), y(newY) {}
	Point(const Point &other) : x(other.x), y(other.y) {}
	~Point() {}

	Point &operator=(const Point &other);

	const Fixed &X() const;
	const Fixed &Y() const;
};
