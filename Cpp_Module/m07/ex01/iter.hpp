#ifndef __ITER_HPP__
#define __ITER_HPP__
#include <iostream>

template<typename T>
void    iter(T *point, int length, void test(T))
{
    for (int i = 0; i < length; i++)
    {
        test(point[i]);
    }
}

template<typename T>
void test(T tmp)
{
    std::cout << tmp << std::endl;
}

#endif
