#include <iostream> // cpp 표준 입출력 헤더
#include <cctype>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for(int i = 1; i < argc; i++)
		{
			std::string str = argv[i];
			for (size_t j = 0; j < str.length(); j++)
			{
				//str[j] = std::toupper(str[j]);
				std::cout << (char)std::toupper(str[j]);
			}
		}
	}
	std::cout << std::endl;
}
