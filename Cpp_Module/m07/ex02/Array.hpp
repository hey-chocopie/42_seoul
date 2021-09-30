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
	Array(void)
	{
		arr_length = 0;
		value = 0;
		//value = new T(0);
	}
	
	Array(unsigned int n)
	{
		arr_length = n;
		value = new T[n];
//		for(int i = 0; i < n; i++)
//			value[i] = 0;
	}
	Array (Array &rhd)
	{
		arr_length = rhd.arr_length;

		this->value = new T [arr_length];
		for(int i = 0; i < arr_length; i++)
		{
			value[i] = rhd.value[i];
		}
	}


	size_t size(void) const
	{
		return arr_length;
	}

	T &operator[](int number)
	{
		if(number >= arr_length || number < 0)
			throw Array::not_grade();
		else
			return (this->value[number]);
	}
	Array &operator=(Array const &rhd)
	{
		arr_length = rhd.arr_length;
	
		if (this->value != 0)
		{
			delete this->value;
			this->value = 0;
		}
		this->value = new T [arr_length];
		for(int i = 0; i < arr_length; i++)
		{
			value[i] = rhd.value[i];
		}
		return *this;
	}

	~Array ( void ){
		if (value != 0)
			delete [] value;
}
};

#endif
