#include "Zombie.hpp"

int main( void )
{
	Zombie a;

	Zombie *b = a.zombieHorde (4, "max");
	for (int i = 0; i < 4; i++)
		b[i].announce();
	delete [] b;
	return (0);
}
