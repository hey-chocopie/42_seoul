#ifndef __MATERIASOURCE_HPP__
#define __MATERIASOURCE_HPP__

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
class MateriaSource : public IMateriaSource{
protected:
	AMateria *(source[4]);
	int count[4];
public:
	MateriaSource();
	MateriaSource(MateriaSource &rhd);

	void learnMateria(AMateria *m);
	AMateria* createMateria(std::string const & type);

	MateriaSource &operator=(const MateriaSource &rhd);

	~MateriaSource();
};

#endif

