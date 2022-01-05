#include "vector.hpp"
#include <vector>
#include <typeinfo>
#include <iostream>

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

void reconfirm(void)
{
	std::cout << RED "check : random_access operater-> " << std::endl;
	std::cout << RED "check : random_access *a = t" << std::endl;
	std::cout << RED "check : random_access n + a" << std::endl; //아마 n+a는 n에서 처리해주지 않을까? // 솔직히 난 모르겠다. 이건 넘어가자. 
	std::cout << RED "check : vector begin, const *a = t" << std::endl;
	std::cout << RED "check : vector construct, ft::vector<int>::a(50, 50) 이게 주소값에 타버림.." << std::endl;
}

int main(void)
{
//	ft::vector<int> a;
//	ft::vector<int> aa(50);
//	std::vector<int> bb(50);
//
//	std::cout << aa.max_size() << std::endl;
//	std::cout << bb.max_size() << std::endl;
////	ft::vector<int> c(ss.begin(), ss.end());
//	

//	std::vector<int> ddd(50,48);
//	ddd.push_back(12);
//	ddd.push_back(100);
//   std::cout << "The length of storage allocated is now "
//        << ddd.capacity( ) << "." << std::endl;
//	std::vector<int> eee(1000);
//	eee.push_back(120);
//	for(int i = 0; i < 1000; i ++)
//		eee.push_back(120);
//	//eee.push_back(120);
//   std::cout << "The length of storage allocated is now "
//        << eee.capacity( ) << "." << std::endl;
//	std::vector<int> xxx(20000);
//   std::cout << "The length of storage allocated is now "
//        << xxx.capacity( ) << "." << std::endl;
//	std::vector<int> zzz(3000000);
//   std::cout << "The length of storage allocated is now "
//        << zzz.capacity( ) << "." << std::endl;
//	reconfirm();

	
	return(0);
}
