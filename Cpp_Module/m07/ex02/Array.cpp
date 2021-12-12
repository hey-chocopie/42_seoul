#include "Array.hpp"

template <typename T>
Array<T>::Array(void)
{
	arr_length = 0;
	value = 0;
}
template <typename T>
Array<T>::Array(unsigned int n)
{
	arr_length = n;
	value = new T[n];
}
template <typename T>
Array<T>::Array (Array &rhd)
{
	arr_length = rhd.arr_length;

	this->value = new T [arr_length];
	for(size_t i = 0; i < arr_length; i++)
	{
		value[i] = static_cast<T> (rhd.value[i]);
	}
}

template <typename T>
size_t Array<T>::size(void) const
{
	return arr_length;
}

template <typename T>
T &Array<T>::operator[](size_t number)
{
	if(number >= arr_length || number < 0)
		throw Array::not_grade();
	else
		return (this->value[number]);
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &rhd)
{
	arr_length = rhd.arr_length;

	if (this->value != 0)
	{
		delete [] this->value;
		this->value = 0;
	}
	this->value = new T [arr_length];
	for(size_t i = 0; i < arr_length; i++)
	{
		value[i] = (rhd.value[i]);
	}
	return *this;
}

template <typename T>
Array<T>::~Array ( void ){
	if (value != 0)
		delete [] value;
}
