#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>

class Animal
{
public:

	Animal( void );
	Animal( const Animal& copy );
	virtual ~Animal( void );

	Animal&	operator=( const Animal& copy );

	std::string	getType( void ) const;

	virtual void	makeSound( void ) const;


protected:

	std::string	_type;

	Animal( const std::string& type );
};

#endif