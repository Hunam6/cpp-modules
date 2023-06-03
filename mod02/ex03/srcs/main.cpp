#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	Point a(0.0f, 0.0f);
	Point b(4.0f, 0.0f);
	Point c(2.0f, 4.0f);

	// inside
	Point p1(2.0f, 2.0f);
	if (bsp(a, b, c, p1))
		std::cout << "Point is inside the triangle\n";
	else
		std::cout << "Point is outside the triangle\n";

	// on the edge (outside)
	Point p2(0.0f, 0.0f);
	if (bsp(a, b, c, p2))
		std::cout << "Point is inside the triangle\n";
	else
		std::cout << "Point is outside the triangle\n";

	// outside
	Point p3(6.0f, 0.0f);
	if (bsp(a, b, c, p3))
		std::cout << "Point is inside the triangle\n";
	else
		std::cout << "Point is outside the triangle\n";
}
