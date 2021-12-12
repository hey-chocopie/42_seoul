#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__
#include <iostream>

template <typename T>
class Array
{
private:
    T *value;
	size_t	arr_length;
public:

	class not_grade : public std::exception{
		const char *what() const throw()
		{return "Error : not array grade"; };
	};
	Array(void);
	Array(unsigned int n);
	Array (Array &rhd);

	size_t size(void) const;

	T &operator[](size_t number);
	Array &operator=(Array const &rhd);
	~Array ( void );
};

//#include "Array.tpp"

#endif
