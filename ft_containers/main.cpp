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



int main(void)
{
//	ft::vector<int> ab(5);
//	ft::vector<int>::const_iterator it = ab.begin();

  ft::vector<int> vct(5);
  ft::vector<int>::iterator it(vct.begin());
  ft::vector<int>::const_iterator ite(vct.end());

  for (int i = 1; it != ite; ++i)
     *it++ = i;
//
//	ft::vector<int> aa(5, 20);
//
//	aa.erase (aa.begin()+2);
//	ft::vector<int>::iterator aa2 = aa.begin();
//	for(int i = 0 ; i < 5; i++)
//	{
//		std::cout << *aa2 << std::endl;
//		aa2++;
//	}
	return(0);
}
