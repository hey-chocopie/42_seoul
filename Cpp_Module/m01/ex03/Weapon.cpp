#include "Weapon.hpp"

const std::string &Weapon::getType( void )
{
	return (Weapon::type);
}

void		Weapon::setType( std::string newtype )
{
	Weapon::type = newtype;
}

Weapon::Weapon( void )
{
	;
}

Weapon::Weapon( std::string type )
{
	Weapon::type = type;
}

Weapon::~Weapon( void )
{
}
