#include "Bureaucrat.hpp"

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
		this->grade = grade;
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
	this->grade--;
	std::cout << "complete increment : " << getGrade() << std::endl;
}
void		Bureaucrat::decrement( void )
{
	if (grade >= 150)
	{
		throw GradeTooLowException( );
	}
	this->grade++;
	std::cout << "complete decrement : " << getGrade() << std::endl;
}

std::string	Bureaucrat::getName(void) const
{
    return (this->Name);
}

int			Bureaucrat::getGrade(void) const
{
    return (this->grade);
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

