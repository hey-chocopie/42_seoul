//#include "AMateria.hpp"
#include "Cure.hpp"

Cure::Cure ( void )
{
    this->type = "cure";
}

Cure::Cure (std::string type)
{
	this->type = "";
    for (size_t i=0; i<type.size(); i++)
        this->type += std::tolower(type[i]);
}

Cure::Cure ( const Cure &rhd )
{
    this->type = "";
    *this = rhd;
}

AMateria* Cure::clone() const
{
    return (new Cure);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure &Cure::operator=( const Cure &rhd )
{
    for (size_t i=0; i<rhd.getType().size(); i++)
        this->type += std::tolower(rhd.getType()[i]);
    return (*this);
}


Cure::~Cure( void )
{
    ;
}

