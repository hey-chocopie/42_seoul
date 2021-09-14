#ifndef __Cure_HPP__
#define __Cure_HPP__
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure: public AMateria
{
private:

public:

	Cure( void );
	Cure(std::string type);
	Cure( const Cure &rhd );

	Cure &operator=( const Cure &rhd );
	AMateria* clone() const;
	void use(ICharacter& target);
	~Cure( void );
};

#endif
