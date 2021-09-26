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

		class MyCustomException : public std::exception{
			public:
			MyCustomException(std::string str):err_str(str){}
			virtual ~MyCustomException() throw(){}
			const char *what() const throw();
			private :

			std::string err_str;
		};

		const std::string	getName( void ) const;
		bool			getSigned( void ) const;
		const int			&getSignGrade( void ) const;
		const int			&getExecuteGrade( void ) const;

		virtual void		execute(Bureaucrat const &rhd) const = 0;
		void				beSigned(const Bureaucrat &rhd);
		void				check_signed_and_grade(Bureaucrat const & rhd) const;

		Form &operator=(Form const &rhd);

		~Form ( void );
		
	private:
		const std::string  Name;
		bool		Signed;
		const int	SignGrade;
		const int	ExecuteGrade;
};

std::ostream& operator<<(std::ostream& os, const Form& B); 

#endif

