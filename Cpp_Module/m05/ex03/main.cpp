#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
int main( void )
{
	try
	{
		std::cout << "--------------------Inter----------------" << std::endl;

		Bureaucrat tmp4("hoylee", 3) ;
		Intern aaa2;

		std::cout << "[test ShrubberyCreationForm]" << std::endl;
		Form *Shr = aaa2.makeForm("Shrubbery CreationForm", "simple1");
		Shr->beSigned(tmp4);
		tmp4.executeForm(*Shr);
		std::cout << std::endl;

		std::cout << "[test RobotomyRequestForm]" << std::endl;
		Form *robo = aaa2.makeForm("robotomy request", "simple2");
		robo->beSigned(tmp4);
		tmp4.executeForm(*robo);
		std::cout << std::endl;

		std::cout << "[test PresidentialPardonForm]" << std::endl;
		Form *Presi = aaa2.makeForm("Presidential Pardon", "simple2");
		Presi->beSigned(tmp4);
		tmp4.executeForm(*Presi);
		std::cout << std::endl;

		delete(Shr);
		delete(robo);
		delete(Presi);
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
