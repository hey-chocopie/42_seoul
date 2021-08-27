#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
int		main(void)
{
	std::cout << "==================[Constructor test]=================" << std::endl;
	FragTrap F_test;
	std::cout << std::endl;

	FragTrap F("hoylee");
	ClapTrap F_tmp("hoylee2");
	std::cout << std::endl;

	FragTrap F_copy(F);
	std::cout << std::endl;


	std::cout << "==================[attack test]=================" << std::endl;
	F.attack("lopper");
	F_tmp.attack("lopper");
	std::cout << std::endl;

	std::cout << "==================[takeDamege test]=================" << std::endl;
	F.takeDamage(5);
	F_tmp.takeDamage(5);

	std::cout << "==================[berepaired test]=================" << std::endl;
	F.beRepaired(10);
	F_tmp.beRepaired(10);
	std::cout << std::endl;

	std::cout << "==================[guardGate test]=================" << std::endl;
	F.highFivesGuys();
	//F_tmp.highFivesGuys();
	//이건 안되겠죠?! test case
	std::cout << std::endl;

	std::cout << "==================[Destructor test]=================" << std::endl;

}
