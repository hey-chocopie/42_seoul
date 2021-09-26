#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{

	try
	{
		Bureaucrat tmp("hohoo", 49) ;
		Form F("cut_Form", 50, 50);
		std::cout << F << std::endl;
		//beSgined는 서명이 안되는 이유가 나오고, signForm은 form에 누가 사인했는지 나옴.
		//F.beSigned(tmp);
		tmp.signForm(F);


		tmp.decrement();
		tmp.decrement();
		

		//F.beSigned(tmp);
		tmp.signForm(F);
	}
	catch (std::exception & e)
	{
	    std::cerr << e.what() << std::endl;
	}
	catch (...)
	{
		;
	}
}
