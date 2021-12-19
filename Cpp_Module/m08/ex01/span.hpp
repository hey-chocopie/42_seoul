#ifndef __SPAN_HPP__
#define __SPAN_HPP__
#include <vector>
class Span{
	private:
		std::vector<int> Number;
		int Number_size;
		int Full_size;

	public:
		Span();
		Span(unsigned int size);
		Span(const Span &rhd);
		~Span();

		void addNumber(int add_data);
		void addNumber(std::vector<int>::iterator it1, std::vector<int>::iterator it2);
		int shortestSpan(void);
		int	longestSpan(void);

		Span &operator=(const Span &rhd);
};

#endif
