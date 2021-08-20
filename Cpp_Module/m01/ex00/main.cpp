#include "Zombie.hpp"

int main( void )
{
	Zombie t("jhon");
	t.announce();

	Zombie *save = t.newZombie("max");
	save->announce();
	delete save;

	t.randomChump( "random" ) ;
	t.announce();
}
