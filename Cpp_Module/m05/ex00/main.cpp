#include "Bureaucrat.hpp"

int main( void )
{
	try
	{
		Bureaucrat tmp("hohoo", 149) ;
		//Bureaucrat tmp2("hihi", 170);
		//1 ~ 150 아니면 에러처리.
		std::cout << tmp << std::endl;
		tmp.decrement();
		tmp.decrement();
	}
	catch (std::exception & e)
	{
	    std::cerr << e.what() << std::endl;
	}
}
