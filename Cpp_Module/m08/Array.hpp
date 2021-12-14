#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__
#include <iostream>
//class 대신 typename T 을 써도되나?
template < class T, size_t arr_length >
class Array
{
	private:
		T value[arr_length];

	public:
		//Array(int args, ...);
		void test(void);
};

#endif


//template < class T, size_t arr_length >
//Array<T, arr_length>::Array(int args, ...)
//{
//    va_list ap;    // 가변 인자 목록 포인터
////	if(arr_length < args)
////		throw aa;
//    va_start(ap, args);    // 가변 인자 목록 포인터 설정
//	std::cout << args;
//	for(int i =0 ; i < args; i++)
//	{
//		std::cout << va_arg(ap, int) << " aa";
//	}
//	std::cout << std::endl;
//}

//template < class T, size_t arr_length >
//void Array<T, arr_length>::test(void)
//{
//	value[0] = 1;
//	std::cout << value[0] << std::endl;
//
//	return ;
//}

//template <class T, size_t arr_length>
//Array<T, arr_length> &Array<T, arr_length>::operator=(Array const &rhd)
//{
//    arr_length = rhd.arr_length;
//
//    if (this->value != 0)
//    {
//        delete [] this->value;
//        this->value = 0;
//    }
//    this->value = new T [arr_length];
//    for(size_t i = 0; i < arr_length; i++)
//    {
//        value[i] = (rhd.value[i]);
//    }
//    return *this;
//}
