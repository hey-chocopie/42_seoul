#ifndef __FORM_HPP__
#define __FORM_HPP__
#include <iostream>
#include <iomanip>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
	public:
		Form ( void );
		Form ( std::string const &Name, int const &SignGrade,int const ExecuteGrade );
		Form (Form &rhd);
	
		class GradeTooHighException : public std::exception{
			const char *what() const throw();
		};
		class GradeTooLowException : public std::exception{
			const char *what() const throw();
		};

		const std::string	getName( void ) const;
		bool				getSigned( void ) const;
		const int			&getSignGrade( void ) const;
		const int			&getExecuteGrade( void ) const;

		void				beSigned(const Bureaucrat &rhd);

		Form &operator=(Form const &rhd);

		~Form ( void );
		
	private:
		const std::string	Name;
		bool				Signed;
		const int			SignGrade;
		const int			ExecuteGrade;
};

std::ostream& operator<<(std::ostream& os, const Form& B); 

#endif

