#include "Array.hpp"

int main( void )
{

	Array<int> a;
	Array<int> b(3);

	b[2] = 3;
	Array<int> c(b);
	Array<int> d;
	try
	{
		std::cout << "===========int test============" << std::endl;
		d = c;
		std::cout << "b[2] = " << b[2] << " " << "c[2] = " << c[2] << " d[2] = " << d[2] << std::endl;
		c[2] = 2;
		d[2] = 1;
		std::cout << "b[2] = " << b[2] << " " << "c[2] = " << c[2] << " d[2] = " << d[2] << std::endl;
//		b[199] = 3; 에러테스트.
	}
	catch(std::exception& e)
	{
		std::cout << e.what() <<std::endl;
	}


	Array<float> a2;
	Array<float> b2(3);
	b2[2] = 3;
	Array<float> c2(b2);
	Array<float> d2;
	try
	{
		std::cout << "===========float test============" << std::endl;
		d2 = c2;
		std::cout << "b2[2] = " << b2[2] << " " << "c2[2] = " << c2[2] << " d2[2] = " << d2[2] << std::endl;
		c2[2] = 2;
		d2[2] = 1;
		std::cout << "b2[2] = " << b2[2] << " " << "c2[2] = " << c2[2] << " d2[2] = " << d2[2] << std::endl;
//		b2[199] = 3; 에러테스트.
	}
	catch(std::exception& e)
	{
		std::cout << e.what() <<std::endl;
	}


	Array<std::string> a3;
	Array<std::string> b3(3);
	b3[2] = "~~test~~";
	Array<std::string> c3(b3);
	Array<std::string> d3;
	try
	{
		std::cout << "===========std::string test============" << std::endl;
		d3 = c3;
		std::cout << "b3[2] = " << b3[2] << " " << "c3[2] = " << c3[2] << " d3[2] = " << d3[2] << std::endl;
		c3[2] = "~~test2~~";
		d3[2] = "~~test3~~";
		std::cout << "b3[2] = " << b3[2] << " " << "c3[2] = " << c3[2] << " d3[2] = " << d3[2] << std::endl;
//		b3[199] = "hiii";// 에러테스트.
	}
	catch(std::exception& e)
	{
		std::cout << e.what() <<std::endl;
	}


	return 0;
}
