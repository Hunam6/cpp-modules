#include "Point.hpp"

Fixed cross(const Point &a, const Point &b, const Point &c)
{
	return (b.X() - a.X()) * (c.Y() - a.Y()) - (b.Y() - a.Y()) * (c.X() - a.X());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed cross1 = cross(a, b, point);
	Fixed cross2 = cross(b, c, point);
	Fixed cross3 = cross(c, a, point);

	if (cross1 == 0 || cross2 == 0 || cross3 == 0)
		return false;

	return (cross1 > 0 && cross2 > 0 && cross3 > 0) || (cross1 < 0 && cross2 < 0 && cross3 < 0);
}
