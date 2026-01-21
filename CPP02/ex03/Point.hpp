#ifndef POINT_H
# define POINT_H

# include "Fixed.hpp"
# include <iostream>

class Point
{
public:

	Point( void );
	Point( const float x, const float y );
	Point( const Point& copy );
	~Point( void );

	Point&	operator=( const Point& copy );

	Fixed	getX( void ) const;
	Fixed	getY( void ) const;


private:

	const Fixed	_x;
	const Fixed	_y;

};

std::ostream	&operator<<( std::ostream& os, const Point& point);

#endif