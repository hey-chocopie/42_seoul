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
}

int main(void)
{
	ft::vector<int> a;
//	ft::vector<int> b(55);

	std::vector<int> ss(4, 55);
//	ft::vector<int> c(ss.begin(), ss.end());
	int *test = 0;
	test = new int(20);
	
	ft::vector<int>::iterator IT;
	//ft::vector<int>::iterator IT2(ss.begin());
		//<<  typeid(ss.begin()).name()<< std::endl;;
	std::vector<int>::iterator IT3(ss.begin());
	ptrdiff_t n = 3;
	std::vector<int>::iterator IT4;
	IT4 = n + IT3;
//	ft::vector<int>::Iterator IT;
//	ft::vector<int>::Iterator IT;
//
	reconfirm();

	return(0);
}
