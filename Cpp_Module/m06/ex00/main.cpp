
#include <stdlib.h>
#include <iostream>
#include "conversion.hpp"

int main(int argc, char* argv[])
{
	std::cout << std::fixed;
	std::cout.precision(1);

	try
	{
		for ( int i = 1; i < argc; i++)
		{
			conversion tests(argv[i]);
			tests.value_print();
		}
	}
	catch (std::exception & e)
	{
	    std::cerr << e.what() << std::endl;
	}

	std::cout.unsetf(std::ios::fixed);
	return 0;
}
