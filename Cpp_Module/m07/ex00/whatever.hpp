#ifndef __WHATEVER_HPP__
#define __WHATEVER_HPP__
#include <iostream>

template <typename T>
void swap(T &a, T &b){
    T tmp;
	tmp = b;
	b = a;
	a = tmp;
}

template <typename T>
T min(T &a, T &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

template <typename T>
T max(T &a, T &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

#endif
