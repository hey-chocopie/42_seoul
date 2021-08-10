#include <iostream>
#include <iomanip>
#include "phone_book.hpp"
int input_data(std::string *str)
{
	std::getline(std::cin, *str);
	if (std::cin.eof())
		return (-1);
	return (0);
}

int routine_search(phone_book (*pb)[8], int index)
{
	std::string str;

	if (index == 0)
		std::cout << "# Add a contact before searching !" << std::endl;
	else
	{	
		std::cout << "|-------------------------------------------|\n"
			<< "|     Index|First Name| Last Name|  Nickname|\n" 
				<< "|-------------------------------------------|\n";
		for (int i = 0; i < index && i < 8; i++)
			(*pb)[i].search_print(&i);
	
		while(1)
		{
			std::cout << " Enter Index to display Informations or 'N' to Exit" << std::endl;
			if (input_data(&str) == -1)
				return (-1);
			if(str.length() == 1 && isdigit(str[0]) && str[0] < '8' && str[0] < index + '0')
			{
				(*pb)[str[0] - '0'].print_book_value();
				break ;
			}
			else if (str.length() == 1 && str == "N")
				break;
		}
	}
	return (0);
}

int main(void)
{
	int index;
	std::string str;
	phone_book pb[8];
	//std::string kind_list[5] = {"first_name", "last_name", "nickname", "phone_index", "darkest_secret"};

	index = 0;
	while(1)
	{
		std::cout << "# Enter your command [ADD, SEARCH, EXIT]:";
		if(input_data(&str) == -1)
			break ;
		if (str == "ADD")
		{
			if (pb[index % 8].ADD(&index) == -1)
				return (1);
			std::cout << "complete" << std::endl;
		}
		else if (str == "SEARCH")
		{
			if(routine_search(&pb, index) == -1)
				return (1);
			std::cout << "complete" << std::endl;
		}
		else if (str == "EXIT")
		{
			for (int i = 0; i < index && i < 8; i++)
				pb[i].clean_data();
			std::cout << "complete" << std::endl;
			break ;
		}
		else
			std::cout << "> Check command" << std::endl;
	}
	return (0);
}
