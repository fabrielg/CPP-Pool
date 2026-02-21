#ifndef CAT_H
# define CAT_H

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
public:

	Cat( void );
	Cat( const Cat& copy );
	~Cat( void );

	Cat&	operator=( const Cat& copy );

	void	makeSound( void ) const;

	Brain*	getBrain( void ) const;


private:

	Brain*	_brain;
};

#endif