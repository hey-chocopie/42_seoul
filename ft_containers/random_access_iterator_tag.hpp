#ifndef __RANDOM_ACCESS_ITERATOR_TAG_HPP__
#define __RANDOM_ACCESS_ITERATOR_TAG_HPP__
#include <iostream>

//======================type_iter_define==================

template <typename v, bool _bool>
struct integral_constant
{
	typedef bool	value_type;

    typedef v type; //type은 false or true
    static const value_type value = _bool; // value은 1 or 0
};

template<typename T>
struct is_integral : public integral_constant<bool, false> {} ; //  아래 있는 상황들 뺴고 다 false

template<>
struct is_integral<bool> : public integral_constant<bool, true> {} ;

	template<>
	struct is_integral<char> : public integral_constant<bool, true> {} ;

	template<>
	struct is_integral<wchar_t> : public integral_constant<bool, true> {} ;

	template<>
	struct is_integral<signed char> : public integral_constant<bool, true> {} ;

	template<>
	struct is_integral<short int> : public integral_constant<bool, true> {} ;

	template<>
	struct is_integral<int> : public integral_constant<bool, true> {} ;

	template<>
	struct is_integral<long int> : public integral_constant<bool, true> {} ;

	template<>
	struct is_integral<long long int> : public integral_constant<bool, true> {} ;

	template<>
	struct is_integral<unsigned char> : public integral_constant<bool, true> {} ;

	template<>
	struct is_integral<unsigned short int> : public integral_constant<bool, true> {} ;

	template<>
	struct is_integral<unsigned int> : public integral_constant<bool, true> {} ;

	template<>
	struct is_integral<unsigned long int> : public integral_constant<bool, true> {} ;

	template<>
	struct is_integral<unsigned long long int> : public integral_constant<bool, true> {} ;


template <typename T>
struct iterator_traits
	{
		typedef	T			value_type;
		typedef T*		pointer;
		typedef T&	reference;
		typedef ptrdiff_t	difference_type;
};
	
	template<typename T>
	struct iterator_traits<T*>
	{
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef	ptrdiff_t						difference_type;
	};
	
	template<typename T>
	struct iterator_traits<T *const>
	{
		typedef T								value_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef	ptrdiff_t						difference_type;
	};

template <typename RI_Type> //RI == Random iterator
struct input_iterator_tag {
	protected:

	public:

		RI_Type											*_ptr;
		typedef ptrdiff_t				difference_type;

//======================all categories	=======================
		input_iterator_tag() :_ptr(0){};
		input_iterator_tag(RI_Type *ptr): _ptr(ptr){};
		input_iterator_tag(input_iterator_tag& rhd) : _ptr(rhd._ptr){};
		input_iterator_tag(const input_iterator_tag<RI_Type> & rhd) : _ptr(rhd._ptr){};
		virtual input_iterator_tag& operator=(const input_iterator_tag &rhd) //b = a;
		{
			if(this == &rhd)
				return (*this);
			this->_ptr = rhd._ptr;
			return (*this);
		}
		input_iterator_tag<RI_Type>& operator++()//++a;
		{
			++(this->_ptr);
			return(*this);
		}
		input_iterator_tag<RI_Type>& operator++(int) //후위
		{
			input_iterator_tag<RI_Type> tmp(*this);
			(this->_ptr)++;
			return(tmp);
		}

		bool operator==(const input_iterator_tag &rhd) const; // a == b
		bool operator!=(const input_iterator_tag &rhd) const; // a != b
	
		RI_Type& operator*() const; //&*a
		RI_Type* operator->() const; // a->m
};

template <typename RI_Type> //RI == Random iterator
struct output_iterator_tag {

		typedef ptrdiff_t				difference_type;
};
template <typename RI_Type> //RI == Random iterator
struct forward_iterator_tag : public input_iterator_tag<RI_Type>, output_iterator_tag<RI_Type>
{
	public:
		typedef ptrdiff_t				difference_type;
//======================all categories	=======================
		forward_iterator_tag() : input_iterator_tag<RI_Type>(){};
		forward_iterator_tag(RI_Type *ptr): input_iterator_tag<RI_Type>(ptr){};
		forward_iterator_tag(forward_iterator_tag& rhd) : input_iterator_tag<RI_Type>(rhd){};
		forward_iterator_tag(const forward_iterator_tag<RI_Type> & rhd) : input_iterator_tag<RI_Type>(rhd){};
		virtual forward_iterator_tag& operator=(const forward_iterator_tag &rhd) //b = a;
		{
			if(this == &rhd)
				return (*this);
			this->_ptr = rhd._ptr;
			return (*this);
		}
		forward_iterator_tag& operator++()//++a;
		{
			++(this->_ptr);
			return(*this);
		}
		forward_iterator_tag& operator++(int) //후위 // 이거 virtual 로 하니까  tmp 가 스텍데이터라고 안되네? 그냥하면 되는데;;
		{
			forward_iterator_tag<RI_Type> tmp(*this);
			(this->_ptr)++;
			return(tmp);
		}
};

template <typename RI_Type> //RI == Random iterator
struct bidirectional_iterator_tag : public forward_iterator_tag<RI_Type>
{
	public:
		typedef ptrdiff_t				difference_type;
//======================all categories	=======================
		bidirectional_iterator_tag() :forward_iterator_tag<RI_Type>(){};
		bidirectional_iterator_tag(RI_Type *ptr): forward_iterator_tag<RI_Type>(ptr){};
		bidirectional_iterator_tag(bidirectional_iterator_tag& rhd) : forward_iterator_tag<RI_Type>(rhd){};
		bidirectional_iterator_tag(const bidirectional_iterator_tag<RI_Type> & rhd) : forward_iterator_tag<RI_Type>(rhd){};
		virtual bidirectional_iterator_tag& operator=(const bidirectional_iterator_tag &rhd) //b = a;
		{
			if(this == &rhd)
				return (*this);
			this->_ptr = rhd._ptr;
			return (*this);
		}

		bidirectional_iterator_tag& operator++()//++a;
		{
			++(this->_ptr);
			return(*this);
		}
		bidirectional_iterator_tag& operator++(int) //후위
		{
			bidirectional_iterator_tag<RI_Type> tmp(*this);
			(this->_ptr)++;
			return(tmp);
		}

		bidirectional_iterator_tag& operator--(); //--a;
		bidirectional_iterator_tag& operator--(int);
};

template <typename RI_Type> //RI == Random iterator
class random_access_iterator_tag : public bidirectional_iterator_tag<RI_Type>, iterator_traits<RI_Type>
{
	public:
		typedef random_access_iterator_tag<RI_Type>							iterator_category;
		typedef typename iterator_traits<RI_Type>::value_type				value_type;
		typedef typename iterator_traits<RI_Type>::difference_type			difference_type;
		typedef typename iterator_traits<RI_Type>::pointer					pointer;
		typedef typename iterator_traits<RI_Type>::reference				reference;

//======================all categories	=======================
//		random_access_iterator_tag(pointer d){std::cout << "ok"<<std::e{};//ndl};
		explicit random_access_iterator_tag() : bidirectional_iterator_tag<RI_Type>(){};
		explicit random_access_iterator_tag(RI_Type *ptr) : bidirectional_iterator_tag<RI_Type>(ptr){};
		random_access_iterator_tag(random_access_iterator_tag<RI_Type>& rhd) : bidirectional_iterator_tag<RI_Type>(rhd){};
		random_access_iterator_tag(const random_access_iterator_tag<RI_Type> & rhd) : bidirectional_iterator_tag<RI_Type>(rhd){};


		random_access_iterator_tag& operator=(const random_access_iterator_tag &rhd) //b = a;
		{
			if(this == &rhd)
				return (*this);
			this->_ptr = rhd._ptr;
			return (*this);
		}
		random_access_iterator_tag& operator++(); //++a;
		random_access_iterator_tag& operator++(int); //후위
////======================random_access_iterator_tag==============
		random_access_iterator_tag operator+(difference_type n) const; //a + n;
		random_access_iterator_tag operator-(difference_type n) const; // a - n;
		difference_type operator-(const random_access_iterator_tag &rhd) const; //a - b;
		friend random_access_iterator_tag operator+(difference_type n, const random_access_iterator_tag &rhd) //n + a 이게 왜 되는건지 모르겠음., 전역으로 할려면 원래 선언하고 써야할텐데 왜 그냥 friend 만 쓰고 되지? friend이해가 필요할듯. 
		{
			return rhd.operator+(n);
		}


		bool operator<(const random_access_iterator_tag &rhd);
		bool operator>(const random_access_iterator_tag &rhd);
		bool operator<=(const random_access_iterator_tag &rhd);

		bool operator>=(const random_access_iterator_tag &rhd);

		random_access_iterator_tag& operator+=(difference_type n); //a + n;
		random_access_iterator_tag& operator-=(difference_type n); // a - n;

		RI_Type operator[](const difference_type n) const;

};



//=============================input_iter==================================

template <typename RI_Type> //RI == Random iterator
bool input_iterator_tag<RI_Type>::operator==(const input_iterator_tag &rhd) const
{
	return (this->_ptr == rhd._ptr);
}

template <typename RI_Type>
bool input_iterator_tag<RI_Type>::operator!=(const input_iterator_tag &rhd) const
{
	return (this->_ptr != rhd._ptr);
}


template <typename RI_Type>
RI_Type &input_iterator_tag<RI_Type>::operator*() const//*a
{
	return (*(this->_ptr));
}

//pointer is T*
template <typename RI_Type>
RI_Type* input_iterator_tag<RI_Type>::operator->() const // 잘모르겠음. 
{
		return (this->_ptr);
}

//===========================Bidirectional======================

template <typename RI_Type>
bidirectional_iterator_tag<RI_Type>& bidirectional_iterator_tag<RI_Type>::operator--()//--a;
{
	--(this->_ptr);
	return(*this);
}
template <typename RI_Type>
bidirectional_iterator_tag<RI_Type>& bidirectional_iterator_tag<RI_Type>::operator--(int) //++a;
{
	random_access_iterator_tag<RI_Type> tmp(*this);
	(this->_ptr)--;
	return(tmp);
}



template <typename RI_Type>
random_access_iterator_tag<RI_Type>& random_access_iterator_tag<RI_Type>::operator++() //++a;
{
	++(this->_ptr);
	return(*this);
}


template <typename RI_Type>
random_access_iterator_tag<RI_Type>& random_access_iterator_tag<RI_Type>::operator++(int) //++a;
{
	random_access_iterator_tag<RI_Type> tmp(*this);
	(this->_ptr)++;
	return(tmp);
}


template <typename RI_Type>
random_access_iterator_tag<RI_Type> random_access_iterator_tag<RI_Type>::operator+(difference_type n) const
{
	return random_access_iterator_tag<RI_Type> (this->_ptr + n);
}
template <typename RI_Type>
random_access_iterator_tag<RI_Type> random_access_iterator_tag<RI_Type>::operator-(difference_type n) const
{
	return random_access_iterator_tag<RI_Type> (this->_ptr - n);
}

//template <typename RI_Type>
//ptrdiff_t random_access_iterator_tag<RI_Type>::operator-(const random_access_iterator_tag &rhd) const //a - b;
//{
//	return (this->_ptr - rhd._ptr);
//}
template <typename RI_Type>
typename iterator_traits<RI_Type>::difference_type random_access_iterator_tag<RI_Type>::operator-(const random_access_iterator_tag &rhd) const //a - b; //리턴값 ptrdiff_t이거 왜 안됨.?
{
	return (this->_ptr - rhd._ptr);
}


template <typename RI_Type>
bool random_access_iterator_tag<RI_Type>::operator<(const random_access_iterator_tag &rhd)
{
	return (this->_ptr < rhd._ptr);
}
template <typename RI_Type>
bool random_access_iterator_tag<RI_Type>::operator>(const random_access_iterator_tag &rhd)
{
	return (this->_ptr > rhd._ptr);
}
template <typename RI_Type>
bool random_access_iterator_tag<RI_Type>::operator<=(const random_access_iterator_tag &rhd)
{
	return (this->_ptr <= rhd._ptr);
}
template <typename RI_Type>
bool random_access_iterator_tag<RI_Type>::operator>=(const random_access_iterator_tag &rhd)
{
	return (this->_ptr >= rhd._ptr);
}

template <typename RI_Type>
random_access_iterator_tag<RI_Type>& random_access_iterator_tag<RI_Type>::operator+=(difference_type n)
{
	this->_ptr = this->_ptr + n;
	return (*this);
}
template <typename RI_Type>
random_access_iterator_tag<RI_Type>& random_access_iterator_tag<RI_Type>::operator-=(difference_type n)
{
	this->_ptr = this->_ptr - n;
	return (*this);
}

template <typename RI_Type>
RI_Type random_access_iterator_tag<RI_Type>::operator[](const difference_type n) const
{
	return (*(this->_ptr + n));
}

//


// reverse iterator
  template<class Iterator, typename RI_Type>
  class reverse_iterator_tag  {
    public:
		typedef Iterator                                                    iterator_type;
		
		typedef random_access_iterator_tag<RI_Type>							iterator_category;
		typedef typename iterator_traits<RI_Type>::value_type				value_type;
		typedef typename iterator_traits<RI_Type>::difference_type			difference_type;
		typedef typename iterator_traits<RI_Type>::pointer					pointer;
		typedef typename iterator_traits<RI_Type>::reference				reference;

    private:
      iterator_type origin_iter;
	public:
      // constructor
		reverse_iterator_tag() : origin_iter() {};
		explicit reverse_iterator_tag(iterator_type it) : origin_iter(it) {};
		template<class iter>
		reverse_iterator_tag(const reverse_iterator_tag<iterator_type, RI_Type>& rev_it) : origin_iter(rev_it.origin_iter) {};

      // destructor
		virtual ~reverse_iterator_tag() {}


      // operator
      reference operator*() const {
        iterator_type tmp = origin_iter;
        return (*(--tmp));
      }

      reverse_iterator_tag operator+(difference_type n) const {
        return (reverse_iterator(origin_iter - n));
      }

      reverse_iterator_tag& operator++() {
        --origin_iter;
        return (*this);
      }
      reverse_iterator_tag operator++(int) {
        reverse_iterator_tag rhd = *this;
        ++(*this);
        return(rhd);
      }

      reverse_iterator_tag& operator+=(difference_type n) {
        origin_iter -= n;
        return (*this);
      }

      reverse_iterator_tag operator-(difference_type n) const {
        return (reverse_iterator(origin_iter + n));
      }

      reverse_iterator_tag& operator--() {
        ++origin_iter;
        return (*this);
      }
      reverse_iterator_tag operator--(int) {
        reverse_iterator_tag rhd = *this;
        --(*this);
        return (rhd);
      }

      reverse_iterator_tag& operator-=(difference_type n) {
        origin_iter += n;
        return (*this);
      }

      pointer operator->() const { return &(operator*()); }

      reference operator[](difference_type n) const {
        return (this->base()[-n - 1]);
      }
    
  };

#endif

//template <typename RI_Type> //RI == Random iterator
//RI_Type* operator*(const random_access_iterator_tag &rhd)
//{
//	return (*(rhd->_ptr));
//}
