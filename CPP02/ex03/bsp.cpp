#include "Point.hpp"

static Fixed	cross(const Point& A, const Point& B, const Point& P)
{
	Fixed	abx = B.getX() - A.getX();
	Fixed	aby = B.getY() - A.getY();
	Fixed	apx = P.getX() - A.getX();
	Fixed	apy = P.getY() - A.getY();

	return (abx * apy) - (aby * apx);
}

bool	bsp(Point const A, Point const B, Point const C, Point const P)
{
	Fixed	c1 = cross(A, B, P);
	Fixed	c2 = cross(B, C, P);
	Fixed	c3 = cross(C, A, P);

	if (c1 == Fixed(0) || c2 == Fixed(0) || c3 == Fixed(0))
		return (false);

	bool	has_neg = ((c1 < Fixed(0)) || (c2 < Fixed(0)) || (c3 < Fixed(0)));
	bool	has_pos = ((c1 > Fixed(0)) || (c2 > Fixed(0)) || (c3 > Fixed(0)));

	return !(has_neg && has_pos);
}
