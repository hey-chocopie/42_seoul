#ifndef __PresidentialPardonForm_HPP__
#define __PresidentialPardonForm_HPP__

#include "Form.hpp"
#include <fstream>
#include "Bureaucrat.hpp"
class PresidentialPardonForm : public Form
{
	private:
		std::string Target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const Target);
		PresidentialPardonForm(PresidentialPardonForm &rhd);
		
		void	execute( Bureaucrat const &rhd ) const;

		PresidentialPardonForm &operator=(PresidentialPardonForm &rhd);

		~PresidentialPardonForm( void );
};

#endif
