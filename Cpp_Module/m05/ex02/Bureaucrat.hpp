#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__
#include <iostream>
#include <iomanip>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat{
	public:
		Bureaucrat ( void );
		Bureaucrat (Bureaucrat &rhd);
		Bureaucrat ( std::string const &Name, int const &grade );
		
		class GradeTooHighException : public std::exception{
			const char *what() const throw();
		};
		class GradeTooLowException : public std::exception{
			const char *what() const throw();
		};
		void		increment( void );
		void		decrement( void );
		std::string getName( void ) const;
		int			getGrade( void ) const;

		void		signForm(Form &F) const;
		void        executeForm(Form const & form) const;
		Bureaucrat &operator=(Bureaucrat const &rhd);

		~Bureaucrat ( void );
		
	private:
		const std::string Name;
		int grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& B);

#endif


