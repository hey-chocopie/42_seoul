#include "MateriaSource.hpp"
#include "AMateria.hpp"


MateriaSource::MateriaSource()
{
	for(int i = 0; i < 4; i++)
	{
		source[i] = 0;
		count[i] = 0;
	}
}

MateriaSource::MateriaSource(MateriaSource &rhd)
{
	for(int i = 0; i < 4; i++)
	{
		source[i] = 0;
		count[i] = 0;
	}
	*this = rhd;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhd)
{
	for(int i = 0; i < 4; i++)
	{
		if(count[i] == 1)
			delete source[i];
		source[i] = 0;
		count[i] = 0;
		if(rhd.count[i] == 1 && rhd.source[i] != 0)
		{
			source[i] = (rhd.source[i])->clone();
			count[i] = 1;
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
	for(int i = 0; i < 4; i++)
	{
		if (count[i] == 0)
		{
			source[i] = m;
			count[i] = 1;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
		if (this->count[i] && !this->source[i]->getType().compare(type))
			return this->source[i]->clone();
	return 0;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if(count[i] == 1)
			delete source[i];
}
