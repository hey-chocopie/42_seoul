#include "vector.hpp"
#include "random_access_iterator_tag.hpp"
#include <vector>
#include <typeinfo>
#include <iostream>

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

#define TESTED_TYPE int

void reconfirm(void)
{
	std::cout << RED "check : random_access operater-> " << std::endl;
	std::cout << RED "check : random_access *a = t" << std::endl;
	std::cout << RED "check : random_access n + a" << std::endl; //아마 n+a는 n에서 처리해주지 않을까? // 솔직히 난 모르겠다. 이건 넘어가자. 
	std::cout << RED "check : vector begin, const *a = t" << std::endl;
	std::cout << RED "check : vector construct, ft::vector<int>::a(50, 50) 이게 주소값에 타버림.." << std::endl;
	std::cout << RED "check : vector void insert 제대로 동작하는지 모르겟다. 확인필요. " << std::endl;
	std::cout << RED "check : erase return 값 다시 보기." << std::endl;

	std::cout << RED "check : iterator_tag들에서 operator++ 를 virtual로 하니까 스텍을 return한다고 에러남.." << std::endl;
}

void at_TEST(void)
{
	ft::vector<TESTED_TYPE> vct(7);
	for (unsigned long int i = 0; i < vct.size(); ++i)
	{
		vct.at(i) = (vct.size() - i) * 3;
		std::cout << "vct.at(): " << vct.at(i) << " | ";
		std::cout << "vct[]: " << vct[i] << std::endl;
	}
	printSize(vct);
	TESTED_NAMESPACE::vector<TESTED_TYPE> const vct_c(vct);
	
	std::cout << "front(): " << vct.front() << " " << vct_c.front() << std::endl;
	std::cout << "back(): " << vct.back() << " " <<  vct_c.back() << std::endl;

	try {
		vct.at(10) = 42;
	}
	catch (std::out_of_range &e) {
		std::cout << "Catch out_of_range exception!" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Catch exception: " << e.what() << std::endl;
	}
	return (0);
}
int main(void)
{
	ft::vector<int> aa(50, 2);

	std::cout << *(aa.begin()) << std::endl;

	return(0);
}
