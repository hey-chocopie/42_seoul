#include "Zombie.hpp"

void Zombie::randomChump( std::string name )
{
	Zombie	tmp(name);
	tmp.announce();
	return ;
}
