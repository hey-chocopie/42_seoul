#include <string>
#include <iostream>
class conversion{
	public:
		conversion ( void );
		conversion (char *num_str);
		conversion ( std::string num_str);
		conversion (conversion const &rhd);

		class WrongInputException : public std::exception{
			public:
				WrongInputException(std::string str):err_str(str){}
				virtual ~WrongInputException() throw(){}
				const char *what() const throw();
			private :
				std::string err_str;
		};
		// class GradeTooLowException : public std::exception{
		// 	const char *what() const throw();
		// };

		// std::string getName( void ) const;
		// int			getGrade( void ) const;
		void value_print( void );

		conversion &operator=(conversion const &rhd);



		~conversion ( void );
		
	private:
		double D_num;
		std::string flag;
};


