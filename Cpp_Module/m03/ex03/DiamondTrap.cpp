#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "[DiamondTrap][Constructor] overwirte" << std::endl;
	DiamondTrap::Name = "Parameter of constructor";
	ClapTrap::setName ("Parameter of constructor + clap_name");
	FragTrap::setHitpoints(42);
	ScavTrap::setEnergy_points(52);
	FragTrap::setAttack_damage(62);
}
DiamondTrap::DiamondTrap(std::string Name)
{
	std::cout << "[DiamondTrap][Constructor] Overwrite ScavTrap, name is " << Name << std::endl;
	DiamondTrap::Name = Name;
	ClapTrap::setName (Name +" + clap_name");
	FragTrap::setHitpoints(42);
	ScavTrap::setEnergy_points(52);
	FragTrap::setAttack_damage(62);
}
DiamondTrap::DiamondTrap(const DiamondTrap& origin)
{
	std::cout << "[DiamondTrap][copy Constructor] Overwrite ScavTrap, name is <" << origin.getName() << ">" << std::endl;
	*this = origin;
}

void	DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack( target );
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << "[DiamondTrap][whoAmI] Hi! my name is " << DiamondTrap::getName() << "!! and ClapTrap Name: " << ClapTrap::getName() << std::endl;
}

void	DiamondTrap::setName(std::string Name)
{
	this->Name = Name;
}

std::string DiamondTrap::getName(void) const
{
	return (Name);
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& origin)
{
	std::cout << "[DiamondTrap][operator=] to " << origin.getName() << std::endl;
	ClapTrap::operator=(origin);
	return *this;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "[DiamondTrap][Destructor]"  <<" <" << DiamondTrap::getName() << "> Called" << std::endl;
}
