#ifndef __ROBOTOMYREQUESTFORM_HPP__
#define __ROBOTOMYREQUESTFORM_HPP__

#include "Form.hpp"
#include <fstream>
#include "Bureaucrat.hpp"
class RobotomyRequestForm : public Form
{
	private:
		std::string Target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const Target);
		RobotomyRequestForm(RobotomyRequestForm &rhd);
		
		void	execute( Bureaucrat const &rhd ) const;

		RobotomyRequestForm &operator=(RobotomyRequestForm &rhd);

		~RobotomyRequestForm( void );
};

#endif
