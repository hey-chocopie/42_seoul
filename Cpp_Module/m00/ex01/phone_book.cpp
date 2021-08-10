#include "phone_book.hpp"

 std::string kind_list[5] = {"first_name", "last_name", "nickname", "phone_index", "darkest_secret"};

int phone_book::ADD(int *index)
	{
		std::cout << "input a new contact’s information" << std::endl;
		if ((*index) / 8 > 0)
			std::cout << "old contact delete and add new contact" << std::endl;
		(*index)++;
		for (int i = 0; i < 5; i++)
		{
			str = "";
			while(str.length() == 0)
			{
				std::cout << kind_list[i] << " = ";
				if(input_data(&str) == -1)
					return (-1);
				if (str.length() == 0)
					std::cout << "Empty contact not added !" << std::endl;
			}
			book_value[i] = str;
		}
		return (0);
	}

	int phone_book::search_print(int *index)
	{
		std::cout <<"|         " << *index << "|";
		for (int i = 0; i < 3; i++)
		{
			if (book_value[i].length() > 10)
				std::cout<< book_value[i].substr(0, 9) << "." << "|";
			else
			{
				std::cout.width(10);
				std::cout<< book_value[i] << "|";
			}
		}
		std::cout << std::endl;
		std::cout << "|-------------------------------------------|" << std::endl;


		return (0);
	}

	void phone_book::print_book_value()
	{
		for (int i = 0; i < 5; i++)
		{
			std::cout << kind_list[i] << " = " << book_value[i] << std::endl;
		}
	}

	void phone_book::clean_data()
	{
		for (int i = 0; i < 5; i++)
			book_value[i] = "";
	}
