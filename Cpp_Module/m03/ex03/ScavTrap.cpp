#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap ( void ): ClapTrap()
{
	std::cout << "[ScavTrap][Constructor] Overwrite ScavTrap" << std::endl;
	ScavTrap::setHitpoints (100);
	ScavTrap::setEnergy_points (50);
	ScavTrap::setAttack_damage (20);
}

ScavTrap::ScavTrap ( std::string name ) : ClapTrap (name)
{
	std::cout << "[ScavTrap][Constructor] Overwrite ScavTrap, name is " << name << std::endl;
	ScavTrap::setHitpoints(100);
	ScavTrap::setEnergy_points(50);
	ScavTrap::setAttack_damage(20);
}

ScavTrap::ScavTrap (const ScavTrap& origin):ClapTrap(origin)
{
	std::cout << "[ScavTrap][copy Constructor] Overwrite ScavTrap, name is <" << origin.getName() << ">" << std::endl;
	*this = origin;
}

void ScavTrap::attack(std::string const & target)
{
	std::cout << "[ScavTrap] <" << ScavTrap::getName() << "> ";
	std::cout << "[attacks] <" << target << ">, ";
	std::cout << "causing <" << ScavTrap::getAttack_damage() << "> ";
	std::cout << "points of damage!" << std::endl;
}
void ScavTrap::guardGate()
{
	std::cout << "[ScavTrap] ScavTrap have enterred in Gate keeper mode!" << std::endl;
}


ScavTrap& ScavTrap::operator=(const ScavTrap& origin)
{
	std::cout << "[ScavTrap][operator=] overwrite" << std::endl;
	ClapTrap::operator=(origin);
	return *this;
}



ScavTrap::~ScavTrap ( void )
{
	 std::cout << "[ScavTrapTrap][Destructor]"  <<" <" << ScavTrap::getName() << "> Called" << std::endl;
}
