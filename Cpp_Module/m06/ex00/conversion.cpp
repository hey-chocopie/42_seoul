	#include "conversion.hpp"
    #include <stdlib.h>

    conversion::conversion ( void )
	{
		D_num = 0;
	}

	conversion::conversion (char *_num_str)
	{
		std::string num_str(_num_str);

		int com = 0;
		if (num_str == "nan" || num_str == "-inf" || num_str == "+inf"
		|| num_str == "-inff" || num_str == "+inff" || num_str == "nanf")
			;
		else
			for (int i = 0; i < num_str.length(); i++)
			{
				if(i == (num_str.length() - 1) && num_str[num_str.length() - 1] == 'f')
					break;
				if(i == 0 && (num_str[i] == '+' || num_str[i] == '-'))
					;
				else if(num_str[i] == '.')
					com++;
				else if(num_str[i] < '0' || num_str[i] > '9' || com == 2)
					throw  WrongInputException("wrong input data.");
			}
		D_num = stod(num_str);
	}

	conversion::conversion (conversion const &rhd)
	{
		this->D_num = rhd.D_num;
	}



	const char *conversion::WrongInputException::what() const throw()
	{
		return (err_str.c_str());
	}

	void conversion::value_print( void )
	{
		//==============static_cast<char>(D_num)================
		if (D_num < 0 || D_num > 127 || isnan(D_num))
			std::cout << "char : " << "impossible" << std::endl;
		else if (D_num < 32)
			std::cout << "char : " << "non printable" << std::endl;
		else
			std::cout << "char : " << static_cast<char>(D_num) << std::endl;

		//==================static_cast<int>(D_num)================
		if (isinf(D_num) || isnan(D_num) || D_num > 2147483647 || D_num < -2147483648)
			std::cout << "int : impossibble" << std::endl;
		else
			std::cout << "int : " << static_cast<int>(D_num) << std::endl;
			
		std::cout << "float : " << static_cast<float>(D_num) << "f" << std::endl;
		std::cout << "double : " << static_cast<double>(D_num) << std::endl;
	}

	conversion &conversion::operator=(conversion const &rhd)
	{
		this->D_num = rhd.D_num;
		return (*this);
	}

	conversion::~conversion ( void )
	{
		;
	}