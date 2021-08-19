#include <iostream>

int		main( void )
{
	std::string str;
	str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "&str adreess : " << &str << std::endl;
	std::cout << "stringPTR adress : " << stringPTR << std::endl;
	std::cout << "&stringREF adress : " << &stringREF << std::endl;

	std::cout << "str string : " << str << std::endl;
	std::cout << "stringPTR string : " << *stringPTR << std::endl;
	std::cout << "stringREF string : " << stringREF << std::endl;
}
