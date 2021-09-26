#include <unistd.h>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Form("robotomy request", 72, 45), Target("my_Roboto")
{
}
RobotomyRequestForm::RobotomyRequestForm(std::string const _Name) : Form("robotomy request", 72, 45), Target(_Name)
{
	;
}


RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &rhd) : Form(rhd)
{
	Target = rhd.Target;
}

void	RobotomyRequestForm::execute(Bureaucrat const &rhd) const
{
	check_signed_and_grade(rhd);

	srand(time(NULL));
	usleep(100 * 1000);
	std::cout << "drrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr" << std::endl;
	if (rand() % 2 == 1)
		std::cout << this->Target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->Target << " failed to robotomized" << std::endl;
	
}


RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &rhd)
{
	this->Target = rhd.Target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	;
}
