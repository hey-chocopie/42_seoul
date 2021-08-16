#include "Pony.hpp"

void	Pony::crying_sound( void )
{
	std::cout << std::setw(20) << "yaaaahaaaaa~~~" << std::endl;
}

void	Pony::sleeping_sound( void )
{
	std::cout << std::setw(20) << "zzzzzzzzzzzzzzz" << std::endl;
}

Pony::Pony( void)
{
	std::cout << std::setw(20) << "make to Pony!!!" << std::endl;
}

Pony::~Pony( void )
{
	std::cout << std::setw(20) << "die to Pony!!!b.b" << std::endl;
}
