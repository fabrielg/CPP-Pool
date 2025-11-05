#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0)
{}

Point::Point( const float x, const float y ) : _x(x), _y(y)
{}

Point::Point( const Point& copy ) : _x(copy._x), _y(copy._y)
{}

Point::~Point( void )
{}

Point&	Point::operator=( const Point& copy)
{
	this->_x = copy._x;
	this->_y = copy._y;
	return (*this);
}

std::ostream	&operator<<( std::ostream& os, const Point& point)
{
	os << "(" << point.getX() << ", " << point.getY() << ")" << std::endl;
	return (os);
}

Fixed	Point::getX( void ) const
{
	return (this->_x);
}

Fixed	Point::getY( void ) const
{
	return (this->_y);
}
