#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point a(0.0f, 0.0f);
	Point b(20.525f, 0.0f);
	Point c(10.0448f, 30.099985f);
	Point p(10.0448f, 30.074589f);

	if (bsp( a, b, c, p ))
		std::cout << "Inside !" << std::endl;
	else
		std::cout << "Outside !" << std::endl;
	return 0;
}