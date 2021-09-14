#ifndef __AMATERIA_HPP__
#define __AMATERIA_HPP__

#include <iostream>
#include <string>
#include <cctype>
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string type;
public:
	AMateria( void );
	AMateria(std::string const & type);

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

	virtual AMateria &operator=(const AMateria &rhd);

	virtual ~AMateria( void );
};

#endif
