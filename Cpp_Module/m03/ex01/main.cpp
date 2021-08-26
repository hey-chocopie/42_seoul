#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int		main(void)
{
	std::cout << "==================[Constructor test]=================" << std::endl;
	ScavTrap A;
	ClapTrap A_tmp;
	std::cout << std::endl;
	ScavTrap B("hoylee");
	std::cout << std::endl;
	ScavTrap C(B);
	std::cout << std::endl;


	std::cout << "==================[attack test]=================" << std::endl;
	A.attack("lopper");
	A_tmp.attack("lopper");
	std::cout << std::endl;

	std::cout << "==================[takeDamege test]=================" << std::endl;
	A.takeDamage(5);
	A_tmp.takeDamage(5);

	std::cout << "==================[berepaired test]=================" << std::endl;
	A.beRepaired(10);
	A_tmp.beRepaired(10);
	std::cout << std::endl;

	std::cout << "==================[guardGate test]=================" << std::endl;
	A.guardGate();
	//A_tmp.guardGate();
	//이건 안되겠죠?! test case
	std::cout << std::endl;

	std::cout << "==================[Destructor test]=================" << std::endl;

}
