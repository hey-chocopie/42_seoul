#include "Zombie.hpp"

int main( void )
{
	Zombie a;

	Zombie *b = a.zombieHorde (3, "max");
//	if (b == 0)
//		std::cout << "zombieHorde first arg is not natural number" << std::endl;
	delete [] b;
	return (0);
}
