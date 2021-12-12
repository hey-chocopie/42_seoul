#ifndef __ITER_HPP__
#define __ITER_HPP__
#include <iostream>

template<typename T, typename T2>
void iter(T *point, T2 length, T test(T))
{
    for (size_t i = 0; i < length; i++)
    {
        test(point[i]);
    }
}

template<typename T>
T test(T tmp)
{
    std::cout << tmp << std::endl;
	return tmp;
}

#endif
