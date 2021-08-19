#include "HumanA.hpp"

HumanA::HumanA ( void )
{
	;
}

HumanA::HumanA ( std::string name, Weapon club )
{
	HumanA::name = name;
	HumanA::club = club;
}

void		HumanA::attack( void )
{
	std::cout << HumanA::name;
	std::cout << " attacks with his ";
	std::cout << HumanA::club.getType() << std::endl;
}
