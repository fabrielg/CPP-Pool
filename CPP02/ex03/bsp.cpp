#include "Point.hpp"
#include <iostream>
#include <cmath>

static float	area( const Point a, const Point b, const Point c )
{
	float x1 = a.getX().toFloat();
	float y1 = a.getY().toFloat();
	float x2 = b.getX().toFloat();
	float y2 = b.getY().toFloat();
	float x3 = c.getX().toFloat();
	float y3 = c.getY().toFloat();

	std::cout << "DEBUG" << std::endl;
	std::cout << "x1 = " << x1 << " y1 = " << y1 << std::endl;
	std::cout << "x2 = " << x2 << " y2 = " << y2 << std::endl;
	std::cout << "x3 = " << x3 << " y3 = " << y3 << std::endl;

	return (
		std::abs(
			(x1 * (y2 - y3)
			+
			x2 * (y3 - y1)
			+
			x3 * (y1 - y2)
			/ 2.0f))
	);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float A = area( a, b, c );
	float A1 = area( point, b, c );
	float A2 = area( a, point, c );
	float A3 = area( a, b, point );

	return (A == A1 + A2 + A3);
}