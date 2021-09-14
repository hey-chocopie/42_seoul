#include "AMateria.hpp"

AMateria::AMateria( void )
{
    this->type = "NONE";
}

AMateria::AMateria( std::string const & type )
{
    this->type = type;
}

std::string const &AMateria::getType( void ) const
{
    return (this->type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* shoots an AMeteria bolt at " << target.getName() << " *" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &rhd)
{
     this->type = rhd.getType();
	 return (*this);
}

AMateria::~AMateria( void )
{
    ;
}
