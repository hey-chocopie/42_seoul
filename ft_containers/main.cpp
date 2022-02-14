#include <iostream>
#include <string>
#include <deque>
#if 1 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include <map.hpp>
	#include <stack.hpp>
	#include <vector.hpp>
#endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	ft::map<int, int> map_int;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}
	
	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(ft::make_pair(rand(), rand()));
	}

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		ft::map<int, int> copy = map_int;
	}
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
	return (0);
}
//
//
//
//#include "vector.hpp"
//#include "vector_iter.hpp"
//#include <vector>
//#include <typeinfo>
//#include <iostream>
//
//#define NC "\e[0m"
//#define RED "\e[0;31m"
//#define GRN "\e[0;32m"
//#define CYN "\e[0;36m"
//#define REDB "\e[41m"
//
//#define TESTED_TYPE int
//
//void reconfirm(void)
//{
//	std::cout << RED "check : random_access operater-> " << std::endl;
//	std::cout << RED "check : random_access *a = t" << std::endl;
//	std::cout << RED "check : random_access n + a" << std::endl; //아마 n+a는 n에서 처리해주지 않을까? // 솔직히 난 모르겠다. 이건 넘어가자. 
//	std::cout << RED "check : vector begin, const *a = t" << std::endl;
//	std::cout << RED "check : vector construct, ft::vector<int>::a(50, 50) 이게 주소값에 타버림.." << std::endl;
//	std::cout << RED "check : vector void insert 제대로 동작하는지 모르겟다. 확인필요. " << std::endl;
//	std::cout << RED "check : erase return 값 다시 보기." << std::endl;
//
//	std::cout << RED "check : iterator_tag들에서 operator++ 를 virtual로 하니까 스텍을 return한다고 에러남.." << std::endl;
//}
//
//
//
//int main(void)
//{
////	ft::vector<int> ab(5);
////	ft::vector<int>::const_iterator it = ab.begin();
//
//  ft::vector<int> vct(5);
//  ft::vector<int>::iterator it(vct.begin());
//  ft::vector<int>::const_iterator ite(vct.end());
//
//  for (int i = 1; it != ite; ++i)
//     *it++ = i;
////
////	ft::vector<int> aa(5, 20);
////
////	aa.erase (aa.begin()+2);
////	ft::vector<int>::iterator aa2 = aa.begin();
////	for(int i = 0 ; i < 5; i++)
////	{
////		std::cout << *aa2 << std::endl;
////		aa2++;
////	}
//	return(0);
//}
