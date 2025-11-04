#include "Point.hpp"
#include "Fixed.hpp"

Point::Point( void ) : _x( Fixed(0) ), _y( Fixed(0) )
{}

Point::Point( const Point& copy)
{
	*this = copy;
}

Point::Point( const float x, const float y )
{
	this->_x = Fixed(x);
	this->_y = Fixed(y);
}

Point::~Point( void )
{}

const Point&	Point::operator=( const Point& copy)
{
	this->_x = copy._x;
	this->_y = copy._y;
	return (*this);
}

Fixed	Point::getX( void ) const
{
	return (this->_x);
}

Fixed	Point::getY( void ) const
{
	return (this->_y);
}
