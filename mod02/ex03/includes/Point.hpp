#pragma once
#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;

public:
	Point();
	Point(float x, float y);
	Point(const Point &other);
	~Point();

	Point &operator=(const Point &other);

	const Fixed &X() const;
	const Fixed &Y() const;
};

#endif
