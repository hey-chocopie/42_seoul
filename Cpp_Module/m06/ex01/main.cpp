//#include "Serialization.hpp"a
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
	uintptr_t tmp =  serialize( A );
	Data *B = deserialize(tmp);
	std::cout << tmp << std::endl;
	std::cout << A << std::endl;
	std::cout << B << std::endl;

	std::cout << "s1 : " <<  A->s1 << " " << B->s1 << std::endl;
	std::cout << "s1 : " <<  A->n << " " << B->n << std::endl;
	std::cout << "s1 : " <<  A->s2 << " " << B->s2 << std::endl;

	delete A;
}
