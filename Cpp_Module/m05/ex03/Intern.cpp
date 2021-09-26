//#include <unistd.h>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
Intern::Intern()
{
}


Intern::Intern(Intern &rhd)
{
	*this = rhd;
}


Intern &Intern::operator=(Intern &rhd)
{
	(void)rhd;
	return (*this);
}

Form *Intern::newShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

Form *Intern::newrobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

Form *Intern::newPresidential(std::string target)
{
	return new PresidentialPardonForm(target);
}

Form *Intern::makeForm(std::string name, std::string target)
{
	std::string form_name[3] = {"Shrubbery CreationForm",
		"robotomy request",
		"Presidential Pardon"};

	Form *(Intern::*f[3])(std::string) =  {
		&Intern::newShrubbery,
		&Intern::newrobotomy,
		&Intern::newPresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if(name == form_name[i])
		{
			return ((this->*f[i])(target));
		}
	}
	std::cout << "Inter misss" << std::endl;
	return (NULL);
}

Intern::~Intern( void )
{
	;
}
