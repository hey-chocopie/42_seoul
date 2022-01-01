#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__
#include <memory>
#include <iostream>
#include <string>
#include "random_access_iterator_tag.hpp"
//class iterator;
namespace ft
{
	// 지금해야할게 배열 생성하고 iterator이 그에따라 작동하는지 확인. 
	template < class T, class Alloc = std::allocator<T> >
	class vector{
		private:

		public:
			//Member types
			typedef T											value_type; //T
			typedef Alloc										allocator_type;
			
			typedef typename allocator_type::reference			reference; //	T&
			typedef typename allocator_type::const_reference	const_reference; //   	const T&
			typedef typename allocator_type::pointer			pointer; //    	T*
			typedef typename allocator_type::const_pointer		const_pointer; //    	const T*


			size_t												_size;
			allocator_type										_alloc;
			T*													_array;
			//지금 이해안되는게, random_access에서 value_type을 받고 
			// iterator에서 기본 벡터 만들었을때 iterator 주소는 없음. 만들어야 할것만 만들것.
			//template<class Category, class T, class Pointer = T*, class Reference = T&>
			class iterator : public random_access_iterator_tag<value_type> // 이거 만들어야함. 
			{
				private:
				public:
					iterator() : random_access_iterator_tag<value_type>(){};
					iterator(value_type* ptr) : random_access_iterator_tag<value_type>(ptr) {};
					iterator(const iterator& rhd) : random_access_iterator_tag<value_type>(rhd) {};
			};
		
			//default (1) //explicit 원치않는 형변환은 컴파일러 실행
			explicit vector (const allocator_type& alloc = allocator_type());
			//fill (2)
			explicit vector (size_t n, const value_type& val = value_type(),
			                 const allocator_type& alloc = allocator_type());
			//range (3)
			template <class Inputiterator>
			         vector (Inputiterator first, Inputiterator last,
			                 const allocator_type& alloc = allocator_type());
//			//copy (4)
//			vector (const vector& x);
//			operator= 만들어서 쓰자. 			
	};


	/* CONSTRUCTORS + DESTRUCTOR */
	template <typename T, class Alloc>
	vector<T, Alloc>::vector(const allocator_type& alloc) : _size(0), _alloc(alloc) //지금 위에서도 빈거 넣었고 _alloc 여기서 또 빈거넣음... 이유가 뭘가?아마 여기 _alloc(alloc)은 지워도 상관없을듯.
	{
		//std::cout << 1 << std::endl;
		//alloc에 뭐가 들어있는지 궁금함. vector<int> a();이렇게 했을때 여기 탈텐데';;
	}
			//fill (2)

	template <typename T, class Alloc>
	vector<T, Alloc>::vector (size_t n, const value_type& val, const allocator_type& alloc) : _size(n), _alloc(alloc)
	{
		//std::cout << " 2  " << std::endl;
		_array = _alloc.allocate(_size);
		for (size_t i = 0; i < _size; i++)
			_alloc.construct(_array + i, val);
	}

	template <typename T, class Alloc>
	template <class Inputiterator>
    vector<T, Alloc>::vector (Inputiterator first, Inputiterator last,
        const allocator_type& alloc) : _size(last - first)
	{
		_array = alloc.allocate(last - first);
		for(int cnt = 0; first != last; first++)
		{
			std::cout << *first << " " << std::endl;
			_alloc.construct(_array + cnt, *first);
			cnt++;
		}
	}

//	template <typename T, class Alloc>
//	vector<T, Alloc>::vector (const vector& x);
//	{
//		*this = x;
//	}
}

#endif
