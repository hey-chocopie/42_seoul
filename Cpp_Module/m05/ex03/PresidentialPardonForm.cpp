#include <unistd.h>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("Presidential Pardon", 25, 5), Target("my_rupang")
{
}
PresidentialPardonForm::PresidentialPardonForm(std::string const _Name) : Form("Presidential Pardon", 25, 5), Target(_Name)
{
	;
}


PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &rhd) : Form(rhd)
{
	Target = rhd.Target;
}

void	PresidentialPardonForm::execute(Bureaucrat const &rhd) const
{
	check_grade_and_signed(rhd);

	std::cout << this->Target << "  has been pardoned by Zafod Beeblebrox." << std::endl;
}


PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &rhd)
{
	this->Target = rhd.Target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	;
}
