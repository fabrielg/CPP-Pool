#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>

class Brain
{
public:

	Brain( void );
	Brain( const Brain& copy );
	~Brain( void );

	const Brain&	operator=( const Brain& copy );


private:

	std::string		_ideas[100];
};

#endif