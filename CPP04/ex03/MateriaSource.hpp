#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

#include "IMateriaSource.hpp"

#define MAX_MATERIAS 4

class MateriaSource : public IMateriaSource
{

public:

	MateriaSource( void );
	MateriaSource( const MateriaSource& cpy );
	~MateriaSource( void );

	MateriaSource&	operator=( const MateriaSource& cpy );

	void		learnMateria( AMateria* materia);
	AMateria*	createMateria( std::string const & type );


private:

	unsigned int	_materiaCount;
	AMateria*		_materias[MAX_MATERIAS];
};

#endif
