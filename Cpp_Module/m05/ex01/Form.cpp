#include "Form.hpp"
#include "Bureaucrat.hpp"
const char *Form::GradeTooHighException::what( void ) const throw()
{
	return "SignGrade or ExecuteGrade is too High";
}

const char *Form::GradeTooLowException::what( void ) const throw()
{
	return "SignGrade or ExecuteGrade is too Low";
}


Form::Form ( void ) : Name("NONE"), Signed(false), SignGrade(1), ExecuteGrade(1)
{
	std::cout << "DEFAULT CONSTRUCTOR SUCCESS" << std::endl;
}

Form::Form ( std::string const &_Name, int const &_SignGrade,int const _ExecuteGrade ) : Name(_Name), Signed(false), SignGrade(_SignGrade), ExecuteGrade(_ExecuteGrade) 
{
	if (SignGrade < 1 || ExecuteGrade < 1)
		throw Form::GradeTooHighException();
	if (SignGrade > 150 || ExecuteGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form (Form &rhd) : Name(rhd.Name), Signed(rhd.Signed), SignGrade(rhd.SignGrade), ExecuteGrade(rhd.ExecuteGrade)
{
	std::cout << "COPY CONSTRUCTOR SUCCESS" << std::endl;
}


const std::string	Form::getName( void ) const
{
	return (this->Name);
}
bool		Form::getSigned( void ) const
{
	return (this->Signed);
}
const int			&Form::getSignGrade( void ) const
{
	return (this->SignGrade);
}
const int		&Form::getExecuteGrade( void ) const
{
	return (this->ExecuteGrade);
}

void                Form::beSigned(const Bureaucrat &rhd)
{
	if(rhd.getGrade() <= this->getSignGrade())
	{
		this->Signed = true;
	}
	else
	{
		throw Bureaucrat::GradeTooLowException();
	}
}


Form &Form::operator=(Form const &rhd)
{
	this->Signed = rhd.Signed;
	return (*this);
}



std::ostream& operator<<(std::ostream& os, const Form& rhd)
{
	std::cout << "[Name] :"  << rhd.getName( ) << " [Sigend] : " <<  rhd.getSigned( ) << " [SignGrade] : " << rhd.getSignGrade( ) << " [ExecuteGrade] : " << rhd.getExecuteGrade();
	return (os);
}

Form::~Form(void)
{
	;
}
