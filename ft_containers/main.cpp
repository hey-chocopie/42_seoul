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
}

int main(void)
{
	ft::vector<int> a;
	ft::vector<int> aa(50);
	std::vector<int> bb(50);

	std::cout << aa.max_size() << std::endl;
	std::cout << bb.max_size() << std::endl;
//	ft::vector<int> c(ss.begin(), ss.end());
	


	reconfirm();
	return(0);
}
