#ifndef __SHRUBBERYCREATIONFORM_HPP__
#define __SHRUBBERYCREATIONFORM_HPP__

#include "Form.hpp"
#include <fstream>
#include "Bureaucrat.hpp"
class ShrubberyCreationForm : public Form
{
	private:
		std::string Target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const Target);
		ShrubberyCreationForm(ShrubberyCreationForm &rhd);
		
		void	execute( Bureaucrat const &rhd ) const;

		ShrubberyCreationForm &operator=(ShrubberyCreationForm &rhd);
		~ShrubberyCreationForm( void );
};


#endif
