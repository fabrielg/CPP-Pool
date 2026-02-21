#ifndef DOG_H
# define DOG_H

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
public:

	Dog( void );
	Dog( const Dog& copy );
	~Dog( void );

	Dog&	operator=( const Dog& copy );

	void	makeSound( void ) const;

	Brain*	getBrain( void ) const;


private:

	Brain*	_brain;
};

#endif