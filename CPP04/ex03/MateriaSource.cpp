#include "MateriaSource.hpp"
#include <cstring>

MateriaSource::MateriaSource( void ) :
	_materiaCount(0),
	_materias()
{}

MateriaSource::MateriaSource( const MateriaSource &cpy ) :
	_materiaCount(0),
	_materias()
{
	for (unsigned int i = 0; i < cpy._materiaCount; i++)
		learnMateria(cpy._materias[i]->clone());
}

MateriaSource::~MateriaSource( void )
{}

MateriaSource	&MateriaSource::operator=( const MateriaSource &cpy )
{
	for (unsigned int i = 0; i < _materiaCount; i++)
		delete (_materias[i]);
	_materiaCount = 0;
	for (unsigned int i = 0; i < cpy._materiaCount; i++)
		learnMateria(cpy._materias[i]->clone());
	return (*this);
}

void	MateriaSource::learnMateria( AMateria *materia ) {
	if (_materiaCount >= MAX_MATERIAS)
		return ;
	_materias[_materiaCount++] = materia;
}

AMateria	*MateriaSource::createMateria( std::string const &type )
{
	for (unsigned int i = 0; i < _materiaCount; i++)
		if (!_materias[i]->getType().compare(type))
			return (_materias[i]);
	return (0);
}