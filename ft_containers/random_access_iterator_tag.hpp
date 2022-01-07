#ifndef __RANDOM_ACCESS_ITERATOR_TAG_HPP__
#define __RANDOM_ACCESS_ITERATOR_TAG_HPP__
#include <iostream>


template <typename RI_Type> //RI == Random iterator
struct input_iterator_tag {
	protected:
		RI_Type											*_ptr;

	public:
		typedef ptrdiff_t				difference_type;

//======================all categories	=======================
		input_iterator_tag() :_ptr(0){};
		input_iterator_tag(RI_Type *ptr): _ptr(ptr){};
		input_iterator_tag(input_iterator_tag& rhd) : _ptr(rhd._ptr){};
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
	
		RI_Type operator*() const; //&*a
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
struct random_access_iterator_tag : bidirectional_iterator_tag<RI_Type>
{
	public:
		typedef ptrdiff_t				difference_type;
//======================all categories	=======================
		random_access_iterator_tag() :bidirectional_iterator_tag<RI_Type>(){};
		random_access_iterator_tag(RI_Type *ptr): bidirectional_iterator_tag<RI_Type>(ptr){};
		random_access_iterator_tag(random_access_iterator_tag& rhd) : bidirectional_iterator_tag<RI_Type>(rhd){};

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
	return (this->_ptr == rhd->_ptr);
}

template <typename RI_Type>
bool input_iterator_tag<RI_Type>::operator!=(const input_iterator_tag &rhd) const
{
	return (this->_ptr != rhd->_ptr);
}


template <typename RI_Type>
RI_Type input_iterator_tag<RI_Type>::operator*() const//*a
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

template <typename RI_Type>
ptrdiff_t random_access_iterator_tag<RI_Type>::operator-(const random_access_iterator_tag &rhd) const //a - b;
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

#endif

//template <typename RI_Type> //RI == Random iterator
//RI_Type* operator*(const random_access_iterator_tag &rhd)
//{
//	return (*(rhd->_ptr));
//}
