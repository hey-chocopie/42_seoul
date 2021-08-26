#include "ClapTrap.hpp"

int		main(void)
{
	ClapTrap A("A");
	ClapTrap B("B");
	ClapTrap C(B);
	std::cout << std::endl;

	A.attack(B.getName());
	A.takeDamage(6);
	A.beRepaired(7);
	std::cout << std::endl;

	B.attack(A.getName());
	B.takeDamage(8);
	B.beRepaired(9);
	std::cout << std::endl;

	C.attack(A.getName());
	C.takeDamage(10);
	C.beRepaired(11);
	std::cout << std::endl;

	return(0);
}

