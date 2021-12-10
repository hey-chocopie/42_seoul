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
			//지금 이런식으로 지역변수를 할당안하고 반환하면, makeForm이 끝나면 f 변수의 공간은 더이상 안전하지 않다. 바로 지워지지는 않을수도 있지만, makeForm가 끝났기 떄문에 해당함수의 지역변수들은 안전하지 않다고 생각해야한다. 과거의 나... 왜 이렇게 짰지?
		}
	}
	std::cout << "Inter misss" << std::endl;
	return (NULL);
}

Intern::~Intern( void )
{
	;
}
