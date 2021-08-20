#include "Karen.hpp"

int main( int argc, char **argv )
{
	int i;
	karen test;
	std::string level;
	std::string data[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (argc != 2)
	{
		std::cout << "FORMAT : ./karenFilter \" level \"";
		return (1);
	}
	level = (std::string)argv[1];
	for(i = 0; i < 4; i++)
	{
		if( data[i] == level )
			break;
	}
	switch(i)
	{
		case 4:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
		case 0:
			test.complain( "DEBUG" );
		case 1:
			test.complain( "INFO" );
		case 2:
			test.complain( "WARNING" );
		case 3:
			test.complain( "ERROR" );
	}
	return (0);
}
