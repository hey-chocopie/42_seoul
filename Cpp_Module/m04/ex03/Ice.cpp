//#include "AMateria.hpp"
#include "Ice.hpp"

Ice::Ice ( void )
{
    this->type = "ice";
}

Ice::Ice (std::string type)
{
	this->type = "";
    for (size_t i=0; i<type.size(); i++)
        this->type += std::tolower(type[i]);
}

Ice::Ice ( const Ice &rhd )
{
    this->type = "";
    *this = rhd;
}

AMateria* Ice::clone() const
{
    return (new Ice);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice &Ice::operator=( const Ice &rhd )
{
    for (size_t i=0; i<rhd.getType().size(); i++)
        this->type += std::tolower(rhd.getType()[i]);
    return (*this);
}


Ice::~Ice( void )
{
    ;
}

