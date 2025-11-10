#ifndef AANIMAL_H
# define AANIMAL_H

# include <iostream>

class AAnimal
{
public:

	AAnimal( void );
	AAnimal( const AAnimal& copy );
	virtual ~AAnimal( void );

	const AAnimal&	operator=( const AAnimal& copy );

	std::string	getType( void ) const;

	virtual void	makeSound( void ) const = 0;


protected:

	std::string	_type;

	AAnimal( const std::string& type );
};

#endif