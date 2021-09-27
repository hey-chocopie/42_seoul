#include <iostream>
#include <stdlib.h>
int check_argv(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "please only one input parameter" << std::endl;
		return (1);
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j]; j++)
			{
				if(argv[i][j] < 32)
				{
					std::cout << "Input parameter is non-printable, can not input non-printable. " <<  std::endl;
					return (1);
				}
				else if (argv[i][j] > 127)
				{
					std::cout << "Input parameter is not ASCII." << std::endl;
					return (1);
				}
			}
		}
	}
	return 0;
}

#include <stdio.h>
int main(int argc, char* argv[])
{
//	if (1 == check_argv(argc, argv))
//		return (0);
//	std::cout << "sucess" << std::endl;

	float F_num= atof("10.12");
	int I_num= atoi("10.12");
	double D_num = std::stod("10.12");
	printf ("%f\n" , F_num);
	//printf ("%d\n" , D_num);

	std::cout << "=="<< F_num << "==" << std::endl;
	std::cout << std::fixed;
	std::cout.precision(6);
	std::cout << I_num << std::endl;
	std::cout << D_num << std::endl;
	std::cout << F_num << std::endl;
	return 0;
}
