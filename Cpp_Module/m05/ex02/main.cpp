#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{
	try
	{
		std::cout << "--------------------ShrubberyCreationForm----------------" << std::endl;
		Bureaucrat tmp("hohoo", 133);
		//Form F("cut_Form", 50, 50);
		//Form은 추상클래스로만들기
		ShrubberyCreationForm WWWW("test_Traget");
		WWWW.beSigned(tmp);
		//WWWW.execute(tmp);
		tmp.executeForm(WWWW);
		//tmp(WWWW);
		tmp.decrement();
		tmp.decrement();
	}
	catch (std::exception & e)
	{
	    std::cerr << e.what() << std::endl;
	}
	catch (...)
	{
		;
	}

	try
	{

		std::cout << "--------------------RobotomyRequestForm----------------" << std::endl;
		Bureaucrat tmp2("hohoo", 40) ;
		RobotomyRequestForm RRRR;
		RRRR.beSigned(tmp2);
		//WWWW.execute(tmp2);
		tmp2.executeForm(RRRR);
		//tmp2(WWWW);
	}
	catch (std::exception & e)
	{
	    std::cerr << e.what() << std::endl;
	}
	catch (...)
	{
		;
	}

	try
	{
		std::cout << "--------------------PresidentialPardonForm----------------" << std::endl;
		Bureaucrat tmp3("hohoo", 3) ;
		PresidentialPardonForm PPPP;
		PPPP.beSigned(tmp3);
		//WWWW.execute(tmp2);
		tmp3.executeForm(PPPP);
		//tmp2(WWWW);
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
