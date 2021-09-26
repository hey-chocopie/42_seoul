#ifndef __INTERN_HPP__
#define __INTERN_HPP__

#include "Form.hpp"
//#include <fstream>
//#include "Bureaucrat.hpp"
class Intern
{
	private:
	public:
		Intern();
		Intern(Intern &rhd);
		
		Intern &operator=(Intern &rhd);

		Form *newShrubbery(std::string target);
		Form *newrobotomy(std::string target);
		Form *newPresidential(std::string target);

		Form *makeForm(std::string name, std::string target);

		~Intern( void );
};

#endif
