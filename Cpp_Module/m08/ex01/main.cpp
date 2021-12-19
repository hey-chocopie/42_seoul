#include <vector>
#include <iostream>
#include <algorithm>
#include "span.hpp"
int main()
{
	std::cout << "============basic test==========" << std::endl;
	Span sp = Span(5);
	sp.addNumber(5);
	//sp.addNumber(5);
	//똑같은거 넣으면 에러
	//sp.addNumber(6);
	//공간없으면 에러
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "============Range 200==========" << std::endl;
	std::vector<int> test(200);
	for(int i = 0; i < 200; i++)
	{
		test[i] = i * 5;
	}
	Span sp2 = Span(200);
	sp2.addNumber(test.begin(), test.end());
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
		
	std::cout << "============Range 100000==========" << std::endl;
	std::vector<int> test3(100000);
	for(int i = 0; i < 100000; i++)
	{
		test3[i] = i * 5;
	}
	Span sp3 = Span(100000);
	sp3.addNumber(test3.begin(), test3.end());
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;

	std::cout << "============copy construct========" << std::endl;
	Span sp4(sp3);

	std::cout << sp4.shortestSpan() << std::endl;
	std::cout << sp4.longestSpan() << std::endl;
}
