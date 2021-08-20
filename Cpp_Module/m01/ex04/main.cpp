#include <iostream>
#include <fstream>

void get_input (std::string *s1, std::string *s2, std::string *filename,
		std::ifstream *read_file, std::ofstream *write_file)
{
	std::cout << "input s1 == ";
	std::getline(std::cin, *s1);
	std::cout << "input s2 == ";
	std::getline(std::cin, *s2);
	std::cout << "input filename == ";
	std::getline(std::cin, *filename);

	read_file->open(*filename);
	*filename = *filename + ".replace";
	if (read_file->is_open())
		write_file->open(*filename);
}

void write_filename_replace(std::string *s1, std::string *s2, std::ifstream *read_file, std::ofstream *write_file)
{
	int find_index;
	std::string str;
	std::string tmp;

	while (!read_file->eof())
    {
		getline(*read_file, str);
		for (size_t i = 0; i < str.length(); i++)
		{
			find_index = -1;
			tmp = str.substr(i);
			if (tmp.find(*s1) != std::string::npos)
				find_index = tmp.find(*s1);
			if(find_index == 0)
			{
				*write_file << *s2;
				i = i + (*s1).length() - 1;
			}
			else
				*write_file << str[i];
		}
		if (!read_file->eof())
			*write_file << std::endl;
	}
}

int main( void )
{
	std::string		s1;
	std::string		s2;
	std::string		filename;
	std::ifstream	read_file;
	std::ofstream	write_file;

	get_input(&s1, &s2, &filename, &read_file, &write_file);
	if(s1 == "" || s2 == ""  || filename == "")
	{
		std::cout << "not access null input" << std::endl;
	}
	else if (!read_file.is_open())
	{
		std::cout << "open read_file error" << std::endl;
		std::cout << "please Check if the file exists" << std::endl;
	}
	else if (!write_file.is_open())
	{
        read_file.close();
		std::cout << "open write_file error" << std::endl;
	}
	else
	{
		write_filename_replace(&s1, &s2, &read_file, &write_file);
        read_file.close();
		write_file.close();
		std::cout << "complete" << std::endl;
    }
	return (0);
}
