#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap ( void ): ClapTrap()
{
	std::cout << "[FragTrap][Constructor] Overwrite FragTrap" << std::endl;
	FragTrap::setHitpoints (100);
	FragTrap::setEnergy_points (100);
	FragTrap::setAttack_damage (30);
}

FragTrap::FragTrap ( std::string name ) : ClapTrap (name)
{
	std::cout << "[FragTrap][Constructor] Overwrite FragTrap, name is " << name << std::endl;
	FragTrap::setHitpoints(100);
	FragTrap::setEnergy_points(100);
	FragTrap::setAttack_damage(30);
}

FragTrap::FragTrap (const FragTrap& origin):ClapTrap(origin)
{
	std::cout << "[FragTrap][copy Constructor] Overwrite FragTrap, name is <" << origin.getName() << ">" << std::endl;
	*this = origin;
}


void FragTrap::highFivesGuys()
{
	std::cout << "[FragTrap] FragTrap highFivesGuys!" << std::endl;
}


FragTrap& FragTrap::operator=(const FragTrap& origin)
{
	std::cout << "[FragTrap][operator=] overwrite" << std::endl;
	ClapTrap::operator=(origin);
	return *this;
}



FragTrap::~FragTrap ( void )
{
	 std::cout << "[FragTrap][Destructor]"  <<" <" << FragTrap::getName() << "> Called" << std::endl;
}
