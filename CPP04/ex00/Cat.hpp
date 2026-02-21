#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"

class Cat : public Animal
{
public:

	Cat( void );
	Cat( const Cat& copy );
	~Cat( void );

	Cat&	operator=( const Cat& copy );

	void	makeSound( void ) const;
};

#endif