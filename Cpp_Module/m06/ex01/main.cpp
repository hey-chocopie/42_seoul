//#include "Serialization.hpp"
#include <iostream>
#include <stdint.h>
#include <string>
struct Data{
	int n;
	std::string s1;
	std::string s2;
};


uintptr_t serialize(Data *ptr)
{
	//reinterpret_cast 은 임의의 포인터 타입끼리 변환을 허용
	// 또는 포인터를 정수로 변환: 그 반대도 가능.
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}


int main( void )
{
	Data *A = new Data;
	
	A->s1 = "hi";
	A->n = 42;
	A->s2 = "bye";

	std::cout << A << std::endl;
	uintptr_t tmp =  serialize( A ); //주소를 정수형태로 저장.
	Data *B = deserialize(tmp); //정수형태를 다시 주소형태로 변환.
	std::cout << tmp << std::endl;
	std::cout << A << std::endl;
	std::cout << B << std::endl;

	std::cout << "s1 : " <<  A->s1 << " " << B->s1 << std::endl;
	std::cout << "s1 : " <<  A->n << " " << B->n << std::endl;
	std::cout << "s1 : " <<  A->s2 << " " << B->s2 << std::endl;

	delete A;
}
