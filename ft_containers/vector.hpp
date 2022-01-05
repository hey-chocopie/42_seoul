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
			void Array_clear_free();
		public:
			//Member types
			typedef T											value_type; //T
			typedef Alloc										allocator_type;
			
			typedef typename allocator_type::reference			reference; //	T&
			typedef typename allocator_type::const_reference	const_reference; //   	const T&
			typedef typename allocator_type::pointer			pointer; //    	T*
			typedef typename allocator_type::const_pointer		const_pointer; //    	const T*
			typedef ptrdiff_t									difference_type;
			typedef size_t										size_type;
//			typedef typename allocator_type::pointer			Inputiterator; //    	T*

			allocator_type										_alloc;
			T*													_array;
			size_type											_size;
			size_type											_capacity;
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
			explicit vector(size_t n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());

			//range (3)
//			template <class InputIterator>
//			         vector (InputIterator first, InputIterator last,
//			                 const allocator_type& alloc = allocator_type());
//
//			//copy (4)
			vector (const vector& x);

//```
//		vector<T, A>(size_type n, value_type const & val = value_type());
//		vector<T, A>(vector<T> const & src);
//		vector<T, A>(InputIterator first, InputIterator last);
//```



			vector& operator= (const vector& rhd); 			

//===========================iterator=======================
			iterator begin();
//			const_iterator begin() const;
			iterator end();
//			const_iterator end() const;
//			reverse_iterator rbegin();
//			const_reverse_iterator rbegin() const;
//		    reverse_iterator rend();
//			const_reverse_iterator rend() const;


//==========================Capacity=======================
			size_type size() const;
			size_type max_size() const;

			void resize (size_type n, value_type val = value_type());
			size_type capacity() const;

			bool empty() const;			
			void reserve (size_type n);



//========================Element accenss:====================
			reference operator[] (size_type n);			
			const_reference operator[] (size_type n) const;

		    reference at (size_type n);
			const_reference at (size_type n) const;

			reference front();
			const_reference front() const;
		    reference back();
			const_reference back() const;
//=======================Modifers=====================
//			template <class InputIterator>
//			void assign (InputIterator first, InputIterator last);
//			void assign (size_type n, const value_type& val);

			void push_back (const value_type& val);
			void pop_back ();

	};
	
// ============hoylee_funtion===========
	template <typename T, class Alloc>
	void vector<T, Alloc>::Array_clear_free()
	{
		if (_array)
		{
			for (size_type i = 0; i < _size; ++i)
				_alloc.destroy(_array + i);
			_alloc.deallocate(_array, _capacity);
			_array = 0;
		}
	}


	/* CONSTRUCTORS + DESTRUCTOR */
	template <typename T, class Alloc>
	vector<T, Alloc>::vector(const allocator_type& alloc) : _array(0), _size(0), _alloc(alloc), _capacity(0) //지금 위에서도 빈거 넣었고 _alloc 여기서 또 빈거넣음... 이유가 뭘가?아마 여기 _alloc(alloc)은 지워도 상관없을듯.
	{
		//std::cout << 1 << std::endl;
		//alloc에 뭐가 들어있는지 궁금함. vector<int> a();이렇게 했을때 여기 탈텐데';;
	}

	template <typename T, class Alloc>
	vector<T, Alloc>::vector (size_t n, const value_type& val, const allocator_type& alloc) : _size(n), _alloc(alloc), _capacity(n)
	{
		//std::cout << " 2  " << std::endl;
		_array = _alloc.allocate(_capacity);
		for (size_t i = 0; i < _size; i++)
			_alloc.construct(_array + i, val);
	}


//	template <typename T, class Alloc>
//	template <class Inputiterator>
//    vector<T, Alloc>::vector (Inputiterator first, Inputiterator last,
//        const allocator_type& alloc) : _alloc(alloc)
//	{
////		this->assign(first, last);
//	} // 이거 만들때capacity 정의 다시볼것. 

	template <typename T, class Alloc>
	vector<T, Alloc>::vector (const vector& x)  
	{
		*this = x;
	}



	template <typename T, class Alloc>
	vector<T, Alloc>& vector<T, Alloc>::operator=(const vector<T, Alloc>& rhd)
	{
		if(this == &rhd)
			return (*this);
		Array_clear_free();
		this->_size = rhd._size;
		this->_alloc = rhd._alloc;
		this->_capacity = rhd._capacity;
		_array = _alloc.allocate(rhd._capacity);
		for (size_t i = 0; i < rhd._size; i++)
			_alloc.construct(_array + i, rhd._array[i]);
		return (*this);
	}

	template <typename T, class Alloc>
	typename vector<T, Alloc>::iterator vector<T, Alloc>::begin()
	{
		return (iterator(_array));
	}
//	template <typename T, class Alloc>
//	typename vector<T, Alloc>::const_iterator vector<T, Alloc>::begin()
//	{
//		return (const_iterator(_array));
//	}

	template <typename T, class Alloc>
	typename vector<T, Alloc>::iterator vector<T, Alloc>::end()
	{
		return (iterator(_array + _size));
	}
//	template <typename T, class Alloc>
//	typename vector<T, Alloc>::const_iterator vector<T, Alloc>::end()
//	{
//		return (const_iterator(_array + _size));
//	}


//	template <typename T, class Alloc>
//	typename vector<T, Alloc>::reverse_iterator rbegin()
//	{
//		return (reverse_iterator(end()));
//	}
//	template <typename T, class Alloc>
//	typename vector<T, Alloc>::const_reverse_iterator rbegin() const;
//	{
//		return (const_reverse_iterator(end()));
//	}
//	template <typename T, class Alloc>
//	typename vector<T, Alloc>::reverse_iterator rend()
//	{
//		return (reverse_iterator(begin()));
//	}
//	template <typename T, class Alloc>
//	typename vector<T, Alloc>::const_reverse_iterator rend() const;
//	{
//		return (const_reverse_iterator(begin()));
//	}




	template <typename T, class Alloc>
	typename vector<T, Alloc>::reference vector<T, Alloc>::operator[] (size_type n)
	{
		return ((this->_array)[n]);
	}	
	
	template <typename T, class Alloc>
	typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[] (size_type n) const
	{
		return ((this->_array)[n]);
	}

				
	template <typename T, class Alloc>
	typename vector<T, Alloc>::size_type vector<T, Alloc>::size() const
	{
		return this->_size;
	}
	template <typename T, class Alloc>
	void vector<T, Alloc>::resize (size_type n, value_type val)
	{
		if (n < _size)
			_size = n;
		else if(n > _size)
		{
			if(n >_capacity)
			{
				for(; _size < n; _size++)
					push_back(val);
				_capacity = n;
			}
			else if(n <= _capacity)
			{
				for(; _size < n; _size++)
					_array[_size] = val;
			}
			// n > _size 는 그냥 push_back 로 해도됨. 
		}
	}
	template <typename T, class Alloc>
	typename vector<T, Alloc>::size_type vector<T, Alloc>::max_size() const
	{
		return (_alloc.max_size()); 
	}

	template <typename T, class Alloc>
	typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity() const
	{
		return (this->_capacity);
	}

	template <typename T, class Alloc>
	bool vector<T, Alloc>::empty() const
	{
		return (_size != 0 ? true : false);
	}			

	template <typename T, class Alloc>
	void vector<T, Alloc>::reserve (size_type n)
	{
		if(_capacity < n)
		{	
			T* tmp = _alloc.allocate(n);
			for(int i = 0; i < _size; i++)
			{
				_alloc.construct(tmp + i, *(_array + i));
			}		
			Array_clear_free();
			_array = tmp;
			_capacity = n;
		}
	}

	template <typename T, class Alloc>
	typename vector<T, Alloc>::reference vector<T, Alloc>::at (size_type n)
	{
        if (n >= size())
	        throw std::out_of_range("vector"); //std의 에러를 던짐 한번 보기. 
		return (*(this->_array + n));
	}

	template <typename T, class Alloc>
	typename vector<T, Alloc>::const_reference vector<T, Alloc>::at (size_type n) const
	{
        if (n >= size())
	        throw std::out_of_range("vector"); //std의 에러를 던짐 한번 보기. 
		return (*(this->_array + n));
	}

	template <typename T, class Alloc>
	typename vector<T, Alloc>::reference vector<T, Alloc>::front()
	{
		return (*(this->_array));
	}
	template <typename T, class Alloc>
	typename vector<T, Alloc>::const_reference vector<T, Alloc>::front() const
	{
		return (*(this->_array));
		return (*(this->_array + _size - 1));
	}
	template <typename T, class Alloc>
	typename vector<T, Alloc>::reference vector<T, Alloc>::back()
	{
		return (*(this->_array + _size - 1));
	}
	template <typename T, class Alloc>
	typename vector<T, Alloc>::const_reference vector<T, Alloc>::back() const
	{
		return (*(this->_array + _size - 1));
	}

//	template <typename T, class Alloc>
//	template <class InputIterator>
//	void vector<T, Alloc>::assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
//	{
//		Array_clear_free();
//		_size = last - first;
//		_capacity = last - first;
//		_array = _alloc.allocate(last - first);
//		for(int i = 0; first != last; first++)
//		{
//			_alloc.construct(_array + i, *first);
//			i++;
//		}
//	}
//
//	template <typename T, class Alloc>
//	void vector<T, Alloc>::assign (size_type n, const value_type& val)
//	{
//		Array_clear_free();
//		_size = n;
//		_capacity = n;
//		_array = _alloc.allocate(n);
//		for(int i = 0; i < n; i++)
//		{
//			_alloc.construct(_array + i, val);
//		}
//	}//이거 좀더 볼것!

template <typename T, class Alloc>
void vector<T, Alloc>::push_back (const value_type& val)
{
	if(_size == _capacity)
		reserve(_capacity * 2);
	_alloc.construct(_array + _size, val);
	_size++;
}

template <typename T, class Alloc>
void vector<T, Alloc>::pop_back ()
{
	if(_size != 0)
		_size--;
	_alloc.destroy(_array + _size); //  이거 아무것도 없는데 계속 destroy해도 상관없는지 테스트해볼땐상관없는데, 한번 다시보자. 
}

}

#endif
