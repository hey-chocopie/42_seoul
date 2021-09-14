#ifndef __ICE_HPP__
#define __ICE_HPP__
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice: public AMateria
{
private:

public:

	Ice( void );
	Ice(std::string type);
	Ice( const Ice &rhd );

	Ice &operator=( const Ice &rhd );
	AMateria* clone() const;
	void use(ICharacter& target);
	~Ice( void );
};

#endif
