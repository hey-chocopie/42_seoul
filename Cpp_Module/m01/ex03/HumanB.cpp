#include "HumanB.hpp"


void		HumanB::attack( void )
{
	std::cout << HumanB::name;
	std::cout << " attacks with his ";
	std::cout << HumanB::club->getType() << std::endl;
}

void		HumanB::setWeapon( Weapon &club )
{
	this->club = &club;
}


HumanB::HumanB ( std::string name )
{
	HumanB::name = name;
}
