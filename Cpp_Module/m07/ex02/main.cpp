#include "Array.hpp"
#include "Array.cpp"
// 제출한 파일은 clang++ main.cpp
// 클래스 템플릿 컴파일 방법이두가지다. 
// 하나는 main에 Array.cpp를 포함해서 컴파일 하기.
// 다른 하나는 Array.hpp파일에 Array.cpp내용을 정의하는 방법이다. 
// 파일을 분리하고 싶어, 제출하는 파일에서는 Array.hpp파일 맨 밑에 #include "Array.hpp"형태로 코드를 불러왔다. 


int main( void )
{
	Array<int> a;
	Array<int> b(3);

	b[2] = 3;
	Array<int> c(b);
	Array<int> d;

	//try chach문은 Array클래스의 객체중에서 인덱스 접근 잘못할때 에러처리할려고 만듬.
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
