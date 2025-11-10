#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

# include <iostream>

class WrongAnimal
{
public:

	WrongAnimal( void );
	WrongAnimal( const WrongAnimal& copy );
	virtual ~WrongAnimal( void );

	const WrongAnimal&	operator=( const WrongAnimal& copy );

	std::string	getType( void ) const;

	void	makeSound( void ) const;


protected:

	std::string	_type;

	WrongAnimal( const std::string& type );
};

#endif