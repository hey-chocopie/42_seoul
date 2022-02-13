#ifndef __RANDOM_ACCESS_ITERATOR_TAG_HPP__
#define __RANDOM_ACCESS_ITERATOR_TAG_HPP__
#include <iostream>

//======================type_iter_define==================


namespace ft
{
	template<bool Cond, class T = void> 
	struct enable_if {};

	template<class T> struct enable_if<true, T> 
	{ 
		typedef T type; 
	};

	template <typename v, bool _bool>
	struct integral_constant
	{
		typedef bool	value_type;

		typedef v type; //type은 false or true
		static const value_type value = _bool; // value은 1 or 0
	};

	template<typename T>
	struct is_integral : public integral_constant<bool, false> {} ; 
	//  설명 : 아래 있는 상황들 뺴고 다 false
	template<>
	struct is_integral<bool> : public integral_constant<bool, true> {} ;
	template<>
	struct is_integral<char> : public integral_constant<char, true> {} ;
	template<>
	struct is_integral<wchar_t> : public integral_constant<wchar_t, true> {} ;
	template<>
	struct is_integral<signed char> : public integral_constant<signed char, true> {} ;
	template<>
	struct is_integral<short int> : public integral_constant<short int, true> {} ;
	template<>
	struct is_integral<int> : public integral_constant<int, true> {} ;
	template<>
	struct is_integral<long int> : public integral_constant<long int, true> {} ;
	template<>
	struct is_integral<long long int> : public integral_constant<long long int, true> {} ;
	template<>
	struct is_integral<unsigned char> : public integral_constant<unsigned char, true> {} ;
	template<>
	struct is_integral<unsigned short int> : public integral_constant<unsigned short int, true> {} ;
	template<>
	struct is_integral<unsigned int> : public integral_constant<unsigned int, true> {} ;
	template<>
	struct is_integral<unsigned long int> : public integral_constant<unsigned long int, true> {} ;
	template<>
	struct is_integral<unsigned long long int> : public integral_constant<unsigned long long, true> {} ;

	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag, output_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
	};

	template<class iterator>
	struct iterator_traits {
		typedef typename iterator::value_type            value_type;
		typedef typename iterator::difference_type       difference_type;
		typedef typename iterator::pointer               pointer;
		typedef typename iterator::reference             reference;
	};

	template<typename RI_Type>
	struct iterator_traits<RI_Type*>
	{
		typedef RI_Type									value_type;
		typedef RI_Type*								pointer;
		typedef RI_Type&								reference;
		typedef	ptrdiff_t								difference_type;
	};

	template<typename T>
	struct iterator_traits<T *const>
	{
		typedef T										value_type;
		typedef const T*								pointer;
		typedef const T&								reference;
		typedef	ptrdiff_t								difference_type;
	};



	template<typename T, class InputIterator>
	typename iterator_traits<T*>::difference_type distance2 (InputIterator first, InputIterator last)
	{
		typename iterator_traits<T*>::difference_type rtn = 0;
		while (first != last)
		{
			first++;
			rtn++;
		}
		return (rtn);
	}

	//RI == Random iterator
	template <typename RI_Type>
	class normal_iter : public iterator<std::random_access_iterator_tag, RI_Type >
	{
	public:

		typedef RI_Type														iterator_type;
		typedef typename iterator_traits<iterator_type*>::value_type		value_type;
		typedef typename iterator_traits<iterator_type*>::difference_type	difference_type;
		typedef typename iterator_traits<iterator_type*>::pointer			pointer;
		RI_Type*										_ptr;
		typedef typename iterator_traits<iterator_type*>::reference			reference;

		//======================construct	=======================
		normal_iter() : _ptr(0){};
		
		normal_iter(RI_Type *ptr) : _ptr(ptr){};
		normal_iter(const normal_iter &rhd) : _ptr(rhd._ptr){};
		
		//설명 : 
		//====================input_iterator_tag==================
		template<typename U>
		bool				operator==(const normal_iter<U> &rhd) const; // a == b
		template<typename U>
		bool				operator!=(const normal_iter<U> &rhd) const; // a != b
		RI_Type&			operator*() const; //&*a
		RI_Type*			operator->() const; // a->m

		//====================bidirectional_iterator_tag=======================
		normal_iter&		operator--(); //--a;
		normal_iter			operator--(int);
		normal_iter&		operator=(const normal_iter &rhd) //b = a;
		{
			if(this == &rhd)
				return (*this);
			this->_ptr = rhd._ptr;
			return (*this);
		}
		normal_iter&		operator++(); //++a;
		normal_iter			operator++(int); //a++
		////==================normal_iter==============
		normal_iter			operator+(difference_type n) const; //a + n;
		normal_iter			operator-(difference_type n) const; // a - n;
		template<typename U>
		difference_type		operator-(const normal_iter<U> &rhd) const; //a - b;
		friend normal_iter	operator+(difference_type n, const normal_iter &rhd) 
		//설명 : 전역으로 할려면 원래 선언하고 써야할텐데 왜 그냥 friend 만 쓰고 되지? friend 이해가 필요할듯. 
		{
			return rhd.operator+(n);
		}
		template<typename U>
		bool				operator<(const normal_iter<U> &rhd) const;
		template<typename U>
		bool				operator>(const normal_iter<U> &rhd) const;
		template<typename U>
		bool				operator<=(const normal_iter<U> &rhd) const;
		template<typename U>
		bool				operator>=(const normal_iter<U> &rhd) const;
		normal_iter&		operator+=(difference_type n); //a + n;
		normal_iter& operator-=(difference_type n); // a - n;
		RI_Type& operator[](const difference_type n) const;

		//변환 연산자 개념 공부!!!
		operator normal_iter<const RI_Type> () const {
         return (normal_iter<const RI_Type>(this->_ptr));
       }
	};



	//=============================input_iter==================================
	//RI == Random iterator
	template <typename RI_Type> 
	template<typename U>
	bool normal_iter<RI_Type>::operator==(const normal_iter<U> &rhd) const
	{
		return (this->_ptr == rhd._ptr);
	}
	template <typename RI_Type>
	template<typename U>
	bool normal_iter<RI_Type>::operator!=(const normal_iter<U> &rhd) const
	{
		return (this->_ptr != rhd._ptr);
	}
	template <typename RI_Type>
	RI_Type &normal_iter<RI_Type>::operator*() const //*a
	{
		return (*(this->_ptr));
	}
	template <typename RI_Type>
	RI_Type* normal_iter<RI_Type>::operator->() const 
	// 설명 : abc -> t 가 있으면, abc->를 주소로 바꾸고 해당주소의 t를 접근 
	{
			return (this->_ptr);
	}

	//===========================Bidirectional======================
	template <typename RI_Type>
	normal_iter<RI_Type>& normal_iter<RI_Type>::operator--() //--a;
	{
		--(this->_ptr);
		return(*this);
	}
	template <typename RI_Type>
	normal_iter<RI_Type> normal_iter<RI_Type>::operator--(int) //a--;
	{
		normal_iter<RI_Type> tmp(*this);
		(this->_ptr)--;
		return(tmp);
	}
	template <typename RI_Type>
	normal_iter<RI_Type>& normal_iter<RI_Type>::operator++() //++a;
	{
		++(this->_ptr);
		return(*this);
	}
	template <typename RI_Type>
	normal_iter<RI_Type> normal_iter<RI_Type>::operator++(int) //++a;
	{
		normal_iter<RI_Type> tmp(*this);
		(this->_ptr)++;
		return(tmp);
	}

	template <typename RI_Type>
	normal_iter<RI_Type> normal_iter<RI_Type>::operator+(difference_type n) const
	{
		return normal_iter<RI_Type> (this->_ptr + n);
	}
	template <typename RI_Type>
	normal_iter<RI_Type> normal_iter<RI_Type>::operator-(difference_type n) const
	{
		return normal_iter<RI_Type> (this->_ptr - n);
	}
	template <typename RI_Type>
	template<typename U>
	typename iterator_traits<RI_Type*>::difference_type normal_iter<RI_Type>::operator-(const normal_iter<U> &rhd) const 
	// 보류 : a - b; 리턴값 ptrdiff_t 이거 왜 안됨.?
	{
		return (this->_ptr - rhd._ptr);
	}
	template <typename RI_Type>
	template<typename U>
	bool normal_iter<RI_Type>::operator<(const normal_iter<U> &rhd) const
	{
		return (this->_ptr < rhd._ptr);
	}
	template <typename RI_Type>
	template<typename U>
	bool normal_iter<RI_Type>::operator>(const normal_iter<U> &rhd) const
	{
		return (this->_ptr > rhd._ptr);
	}
	template <typename RI_Type>
	template<typename U>
	bool normal_iter<RI_Type>::operator<=(const normal_iter<U> &rhd) const
	{
		return (this->_ptr <= rhd._ptr);
	}
	template <typename RI_Type>
	template<typename U>
	bool normal_iter<RI_Type>::operator>=(const normal_iter<U> &rhd) const
	{
		return (this->_ptr >= rhd._ptr);
	}
	template <typename RI_Type>
	normal_iter<RI_Type>& normal_iter<RI_Type>::operator+=(difference_type n)
	{
		this->_ptr = this->_ptr + n;
		return (*this);
	}
	template <typename RI_Type>
	normal_iter<RI_Type>& normal_iter<RI_Type>::operator-=(difference_type n)
	{
		this->_ptr = this->_ptr - n;
		return (*this);
	}
	template <typename RI_Type>
	RI_Type& normal_iter<RI_Type>::operator[](const difference_type n) const
	{
		return (*(this->_ptr + n));
	}

//	// const_iterator
//	template <typename RI_Type>
//	class const_iterator : public iterator<std::random_access_iterator_tag, RI_Type > {
//	protected:
//	typedef RandIte<RI_Type> super;
//	const_iterator(RI_Type *src) : RandIte<RI_Type>(src) {};
//	public:
//	const_iterator(void) : RandIte<RI_Type>() {};
//	const_iterator(const RandIte<RI_Type> &src) : RandIte<RI_Type>(src) {};
//
//	typedef const &		reference;
//	typedef const value_type*		pointer;
//
//	reference			operator*(void) const;
//	pointer				operator->(void) const;
//	const_iterator		&operator+=(difference_type n);
//	const_iterator		&operator-=(difference_type n);
//	reference			operator[](difference_type n) const;
//
//	difference_type		operator-(const RandIte<value_type> &n) const { return super::operator-(n); };
//	const_iterator		operator-(difference_type n) const { return super::operator-(n); };
//	const_iterator		operator+(difference_type n) const { return super::operator+(n); };
//	friend const_iterator	operator+(difference_type n, const const_iterator &rhs) { return rhs.operator+(n); };
//
//	const_iterator		&operator++(void) { super::operator++(); return *this; };
//	const_iterator		operator++(int) { return super::operator++(0); };
//	const_iterator		&operator--(void) { super::operator--(); return *this; };
//	const_iterator		operator--(int) { return super::operator--(0); };
//
//	friend class vector;
//	};

	// reverse iterator
	template<class Iterator>
	class reverse_iterator_tag  
	{
	public:
		typedef Iterator											iterator_type;
		typedef typename iterator_traits<Iterator>::value_type				value_type;
		typedef typename iterator_traits<Iterator>::difference_type			difference_type;
		typedef typename iterator_traits<Iterator>::pointer					pointer;
		typedef typename iterator_traits<Iterator>::reference				reference;

	private:
		iterator_type _ptr;
	public:
		reverse_iterator_tag() : _ptr() {};
		reverse_iterator_tag(iterator_type ptr) : _ptr(ptr) {};
		template<class iter>
		reverse_iterator_tag(const reverse_iterator_tag<iter>& rev_it) : _ptr(rev_it.base()) {};
		virtual ~reverse_iterator_tag() {}

		reference operator*() const 
		{
		iterator_type tmp = _ptr;
		return (*(--tmp));
		}

		reverse_iterator_tag operator+(difference_type n) const {
		return (reverse_iterator_tag(_ptr - n));
		}
		reverse_iterator_tag& operator++() {
		--_ptr;
		return (*this);
		}
		reverse_iterator_tag operator++(int) {
		reverse_iterator_tag rhd = *this;
		++(*this);
		return(rhd);
		}
		reverse_iterator_tag& operator+=(difference_type n) {
		_ptr -= n;
		return (*this);
		}
		reverse_iterator_tag operator-(difference_type n) const {
		return (reverse_iterator_tag(_ptr + n));
		}
		reverse_iterator_tag& operator--() {
		++_ptr;
		return (*this);
		}
		reverse_iterator_tag operator--(int) 
		{
		reverse_iterator_tag rhd = *this;
		++(_ptr);
		return (rhd);
		}

		reverse_iterator_tag& operator-=(difference_type n) {
		_ptr += n;
		return (*this);
		}
		pointer operator->() const { return &(operator*()); }
//		reference operator[](difference_type n) const {
//		return (this->_arrau[-n - 1]);
//		}
		reference operator[](difference_type n) const { return *this->operator+(n); };
		iterator_type base() const
		{
			return (this->_ptr);
		}
		//설명 : operator= c+11에 있는데 사용하는 테스트기에 테스트가 있어서 만듬
		template <class Iter>
		reverse_iterator_tag& operator= (const reverse_iterator_tag<Iter>& rev_it)
		{
			this->_ptr = rev_it.base();
			return (*this);
		}
	};

	//===========================Non-member function overloads======================
	template <class Iterator>
	reverse_iterator_tag<Iterator> operator+ (
            typename reverse_iterator_tag<Iterator>::difference_type n,
             const reverse_iterator_tag<Iterator>& rev_it)
	{
		return (reverse_iterator_tag<Iterator>(rev_it.base() - n)); //base 이름 바꾸자.
	}
	 
	// 설명 : reverse_iterator - const_reverse_iterator
	// 설명 : 이거 c+11기능인데, 테스트케이스에 있어서 그냥 해줬음.
	// 설명 : c+98에는 left, right같은 타입만 받음.
	template <class Iterator_left, class Iterator_right>
	ptrdiff_t operator- (
            const reverse_iterator_tag<Iterator_left>& lhs,
             const reverse_iterator_tag<Iterator_right>& rhs)
	{
		return (rhs.base() - lhs.base()); //base 이름 바꾸자.
	}

template <class Iterator1, class Iterator2>
  bool operator== (const reverse_iterator_tag<Iterator1>& lhs,
                   const reverse_iterator_tag<Iterator2>& rhs)
	{ return (lhs.base() == rhs.base()); }
template <class Iterator1, class Iterator2>
  bool operator!= (const reverse_iterator_tag<Iterator1>& lhs,
                   const reverse_iterator_tag<Iterator2>& rhs)
	{ return (lhs.base() != rhs.base()); }

template <class Iterator1, class Iterator2>
  bool operator<  (const reverse_iterator_tag<Iterator1>& lhs,
                   const reverse_iterator_tag<Iterator2>& rhs)
	{ return (lhs.base() > rhs.base()); }
template <class Iterator1, class Iterator2>
  bool operator<= (const reverse_iterator_tag<Iterator1>& lhs,
                   const reverse_iterator_tag<Iterator2>& rhs)
	{ return (lhs.base() >= rhs.base()); }
template <class Iterator1, class Iterator2>
  bool operator>  (const reverse_iterator_tag<Iterator1>& lhs,
                   const reverse_iterator_tag<Iterator2>& rhs)
	{ return (lhs.base() < rhs.base()); }
template <class Iterator1, class Iterator2>
  bool operator>= (const reverse_iterator_tag<Iterator1>& lhs,
                   const reverse_iterator_tag<Iterator2>& rhs)
	{ return (lhs.base() <= rhs.base()); }



}

#endif

//template <typename RI_Type> //RI == Random iterator
//RI_Type* operator*(const random_access_iterator_tag &rhd)
//{
//	return (*(rhd->_ptr));
//}
