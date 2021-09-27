#include <iostream>
#include <stdlib.h>
int check_argv(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "please only one input parameter" << std::endl;
		return (1);
	}
//	else
//	{
//		for (int i = 1; i < argc; i++)
//		{
//			for (int j = 0; argv[i][j]; j++)
//			{
//				if(argv[i][j] < 32)
//				{
//					std::cout << "Input parameter is non-printable, can not input non-printable. " <<  std::endl;
//					return (1);
//				}
//				else if (argv[i][j] > 127)
//				{
//					std::cout << "Input parameter is not ASCII." << std::endl;
//					return (1);
//				}
//			}
//		}
//	}
	return 0;
}

#include <stdio.h>
int main(int argc, char* argv[])
{
	if (1 == check_argv(argc, argv))
		return (0);
//	float AA = 2.2f;
//	std::string str = "2.2f";

	// for(int i = 1; i < argc; i++)
	// {
	// 	printf("%f\n", atof(argv[i]));
	// 	std::cout << std::fixed;
	// 	std::cout.precision(6);
	// 	std::cout << atof(argv[i]) << std::endl;
	// 	std::cout.unsetf(std::ios::fixed);
	// }

	float F_num;
	std::string num_str;
	num_str = "nasnf";
	std::cout  << stof(num_str) << std::endl;;
	return 0;
}
