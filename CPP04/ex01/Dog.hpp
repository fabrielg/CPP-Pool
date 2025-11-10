#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
public:

	Dog( void );
	Dog( const Dog& copy );
	~Dog( void );

	const Dog&	operator=( const Dog& copy );

	void	makeSound( void ) const;


private:

	Brain*	_brain;
};

#endif