#include "HumanA.hpp"

HumanA::HumanA ( std::string name, Weapon &club ) : C(club)
{
	HumanA::name = name;
}

void		HumanA::attack( void )
{
	std::cout << HumanA::name;
	std::cout << " attacks with his ";
	std::cout << HumanA::C.getType() << std::endl;
}
