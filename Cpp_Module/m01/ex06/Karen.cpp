#include "Karen.hpp"

void	karen::debug ( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void	karen::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void	karen::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout <<  "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void	karen::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void	karen::nothing( void )
{
	std::cout << "Level is not included anywhere." << std::endl;
}

void	karen::complain( std::string level )
{
	void	(karen::*exec_func)(void);

	exec_func = &karen::nothing;
	(!level.compare("DEBUG") && (exec_func = &karen::debug));
	(!level.compare("INFO") && (exec_func = &karen::info));
	(!level.compare("WARNING") && (exec_func = &karen::warning));
	(!level.compare("ERROR") && (exec_func = &karen::error));
	(this->*exec_func)();
}

