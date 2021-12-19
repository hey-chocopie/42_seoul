#include <iostream>
#include "span.hpp"


Span::Span() : Number(0)
{
	Number_size = 0;
	Full_size = 0;
}

Span::Span(unsigned int size) : Number(size)
{
	Number_size = size;
	Full_size = 0;
}

Span::Span(const Span &rhd)
{
	(*this) = rhd;
}

Span::~Span()
{
}

void Span::addNumber(int add_data)
{
	try{
		if(Full_size == Number_size)
			throw std::invalid_argument(std::to_string(add_data) + " : Number is Full, can't not push data");
		std::vector<int>::iterator tmp = find(Number.begin(), Number.begin() + Full_size, add_data);
		if(tmp == Number.begin() + Full_size)
		{
			Number[Full_size] = add_data;
			Full_size++;
		}
		else
			throw std::invalid_argument(std::to_string(add_data) + " : is already exists for Numbers.");
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void Span::addNumber(std::vector<int>::iterator it1, std::vector<int>::iterator it2)
{
	try{
		if(Number_size - Full_size < it2 - it1)
			throw std::invalid_argument("Input range is big than Number free spare");
		else
		{
			for(; it1 != it2; it1++)
			{
				Number[Full_size] = *it1;
				Full_size++;
			}
		}
	}
	catch(std::exception& e){
		 std::cout << e.what() << std::endl;
	}
}

int Span::shortestSpan(void)
{
	try{
		if(Full_size < 2)
			throw std::invalid_argument("Can't not excute longestSpan Becuase fulling_size is 0 or 1 ");
		std::sort(Number.begin(), Number.begin() + Full_size);
		int short_span = 2147483647;
		for(int i = 0; i < Full_size - 1; i++)
		{
			if(Number[i + 1] - Number[i] < short_span)
				short_span = Number[i + 1] - Number[i];
		}
		return short_span;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return -1;
	}
}

int Span::longestSpan(void)
{
	try{
		if(Full_size < 2)
			throw std::invalid_argument("Can't not excute longestSpan Becuase fulling_size is 0 or 1 ");
		std::sort(Number.begin(), Number.begin() + Full_size);
		return Number[Full_size - 1] - Number[0];
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return -1;
	}
}

Span &Span::operator=(const Span &rhd)
{
    this->Number_size = rhd.Number_size;
    this->Full_size = rhd.Full_size;
    this->Number = rhd.Number;
    return (*this);
}


