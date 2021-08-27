#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int		main(void)
{
	DiamondTrap A;
	std::cout << std::endl;

	std::cout << A.getName() << std::endl;
	std::cout << A.ClapTrap::getName() << std::endl;
	std::cout << std::endl;

	A.ScavTrap::attack("cpp03");
	A.attack("cpp03");
	std::cout << std::endl;

	std::cout << "FragTrap::getHitpoints : " << A.FragTrap::getHitoints() << "      getHitpoints : " << A.getHitoints() << std::endl;
	std::cout << "ScavTrap::getEnergy points : " << A.ScavTrap::getEnergy_points() << "  getEnergy points : " << A.getEnergy_points() <<  std::endl;
	std::cout << "FragTrap::getAttack damage : " << A.FragTrap::getAttack_damage() <<  "  getAttack damage : " << A.getAttack_damage() << std::endl;
	std::cout << std::endl;

	A.beRepaired(1000);
	A.takeDamage(9999);
	A.guardGate();
	A.highFivesGuys();
	A.whoAmI();
	std::cout << std::endl;
}
