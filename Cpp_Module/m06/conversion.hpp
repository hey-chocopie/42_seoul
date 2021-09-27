#include <string>

class conversion{
	public:
		conversion ( void );
		conversion ( std::string num_str);
		conversion (conversion &rhd);

		// class GradeTooHighException : public std::exception{
		// 	const char *what() const throw();
		// };
		// class GradeTooLowException : public std::exception{
		// 	const char *what() const throw();
		// };

		// std::string getName( void ) const;
		// int			getGrade( void ) const;

		conversion &operator=(conversion const &rhd);

		~conversion ( void );
		
	private:
		float F_num;
		std::string flag;
};

		conversion::conversion ( void )
		{
			F_num = 0;
		}

		conversion::conversion (std::string num_str)
		{
			if (num_str == "nan" || num_str == "-inf" || num_str == "+inf"  -inff,  +inff, nanf)
			F_num = atof(num_str);
		}

		conversion::conversion (conversion const &rhd)
		{
			this->F_num = rhd.F_num;
		}