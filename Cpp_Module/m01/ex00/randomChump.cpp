#include "Zombie.hpp"

void Zombie::randomChump( std::string name )
{
	int     random;
	std::string name_list[10] = {"Muller", "Frantic", "Hacker", "Haunter", "Bloomer",
                                "Climber", "Tester", "Tumbler", "Chunky", "Dasher"};
	
	srand(time(NULL));
	random = rand() % 10 ;
	std::cout << "rand ==  "<<  rand() << std::endl;
	Zombie	tmp(name_list[random]);
	tmp.announce();
	return ;
}
