#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

Bureaucrat::Bureaucrat ( void ) : Name("NONE")
{
	this->grade = 1;
}

Bureaucrat::Bureaucrat ( std::string const &_Name, int const &grade ) : Name(_Name)
{
	if (grade < 1)
	{
		throw GradeTooHighException(  );
	}
	else if (grade > 150)
	{
		throw GradeTooLowException(  );
	}
	else
	{
		this->grade = grade;
	}
}

Bureaucrat::Bureaucrat (Bureaucrat &rhd)
{
	*this = rhd;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "BureaucratException: Grade too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "BureaucratException: Grade too Low";
}


void		Bureaucrat::increment( void )
{
	if (grade <= 1)
	{
		throw GradeTooHighException( );
	}
	else
	{
		this->grade--;
		std::cout << "complete increment : " << getGrade() << std::endl;
	}
}
void		Bureaucrat::decrement( void )
{
	if (grade >= 150)
	{
		throw GradeTooLowException( );
	}
	else
	{
		this->grade++;
		std::cout << "complete decrement : " << getGrade() << std::endl;
	}
}

std::string	Bureaucrat::getName(void) const
{
    return (this->Name);
}

int			Bureaucrat::getGrade(void) const
{
    return (this->grade);
}


void		Bureaucrat::signForm(Form &F) const
{
	try
	{
		F.beSigned(*this);
		std::cout << "<" << this->getName() << "> signs <" << F.getName() << ">" << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << "<" << this->getName() << "> signs <" << F.getName() << "> because < " << e.what() << ">" << std::endl;
		throw 0;
	}
}

void		Bureaucrat::executeForm(Form const & form) const
{
	form.execute(*this);
	std::cout << this->getName() << " executes " << form.getName() << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhd)
{
	this->grade = rhd.grade;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &B)
{
	os << "<" << B.getName() << ">, bureaucrat grade <" << B.getGrade() << ">.";
	return (os);
}

Bureaucrat::~Bureaucrat(void)
{
	;
}

