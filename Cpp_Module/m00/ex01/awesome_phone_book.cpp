#include <iostream>

int input_data(std::string *str)
{
	std::getline(std::cin, *str);
	if (std::cin.eof())
		return (-1);
	return (0);
}

class phone_book
{
public:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	int ADD(std::string *kind_list, std::string *str, int *index)
	{
		if (*index == 7)
			*index = 0;
		else
			(*index)++;
		for (int i = 0; i < 5; i++)
		{
			(*str) = "";
			while((*str).length() == 0)
			{
				std::cout << kind_list[i] << " = ";
				if(input_data(str) == -1)
					return (-1);
				if (str->length() == 0)
					std::cout << "Empty contact not added !" << std::endl;
			}
			if (i == 0)
				first_name = *str;
			else if(i == 1)
				last_name = *str;
			else if(i == 2)
				nickname = *str;
			else if(i == 3)
				phone_number = *str;
			else if(i == 4)
				darkest_secret = *str;
		}
		return (0);
	}
};

//cout 는 표준 출력 // cin은 표준 입력
int main(void)
{
	int index;
	std::string str;
	phone_book pb[8];
	std::string kind_list[5] = {"first_name", "last_name", "nickname", "phone_index", "darkest_secret"};

	index = 0;
	while(1)
	{
		std::cout << "# Enter your command [ADD, SEARCH, EXIT]:";
		if(input_data(&str) == -1)
			break ;
		if (str == "ADD")
		{
			std::cout << "input a new contact’s information" << std::endl;
			if (pb[index].ADD(kind_list, &str, &index) == -1)
				break ;
		}
//		if (str == "search")
//		{
//
//		}
//		if (str == "ADD" || str == "EXIT" || str == "search")
//		{
//			std::cout << "hi\n";
//		}
		std::cout << "complete" << std::endl;
	}
	return (0);
}
