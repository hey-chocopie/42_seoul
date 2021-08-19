#include "Zombie.hpp"

void	Zombie::input_name(std::string name)
{
	Zombie::name = name;
}

Zombie* Zombie::zombieHorde( int N, std::string name )
{
	if (N >= 1 && N <= 2147483647)
	{
		Zombie *first = new Zombie[N];
		for(int i = 0; i < N; i++)
		{
			first[i].input_name(name);
			first[i].announce();
		}
		return (first);
	}
	return (0);
}
