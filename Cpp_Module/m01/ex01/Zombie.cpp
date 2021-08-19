#include "Zombie.hpp"

void Zombie::announce( void )
{
    std::cout << "<" << Zombie::name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie( std::string name )
{
	Zombie::name = name;
}

Zombie::Zombie( void )
{
	Zombie::name = "not name";
}

Zombie::~Zombie( void )
{
	std::cout << "<" << Zombie::name << ">" << " die" << std::endl;
}
