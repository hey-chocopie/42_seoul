#ifndef __RANDOM_ACCESS_ITERATOR_TAG_HPP__
#define __RANDOM_ACCESS_ITERATOR_TAG_HPP__
template <typename RI_Type> //RI == Random iterator
class random_access_iterator_tag{
	protected:
		RI_Type											*_ptr; //데이터 저장할 배열.
	public:
		typedef ptrdiff_t				difference_type;

		random_access_iterator_tag();
		random_access_iterator_tag(const RI_Type *ptr);
		random_access_iterator_tag(const random_access_iterator_tag& rhd);

		random_access_iterator_tag& operator=(const random_access_iterator_tag &rhd); //b = a;

		bool operator==(const random_access_iterator_tag &rhd) const; // a == b
		bool operator!=(const random_access_iterator_tag &rhd) const; // a != b
		RI_Type operator*() const; //&*a
		RI_Type* operator->() const; // a->m
//// 후위 연산자만 const 반환형인 이유는
// // C++연산 특성과 똑같이 해서 (pos++)++;
		random_access_iterator_tag& operator++(); //++a;
		random_access_iterator_tag& operator--(); //--a;
		random_access_iterator_tag& operator++(int); //후위
		random_access_iterator_tag& operator--(int);

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


//
//		// template <typename T>
//		// random_access_iterator_tag operator+(T How);
//		// template <typename T>
//		// random_access_iterator_tag operator-(int How);
//
//
template <typename RI_Type> //RI == Random iterator
random_access_iterator_tag<RI_Type>::random_access_iterator_tag()  : _ptr(0) {};


template <typename RI_Type> //RI == Random iterator
random_access_iterator_tag<RI_Type>::random_access_iterator_tag(const RI_Type *ptr) : _ptr(ptr){};


template <typename RI_Type> //RI == Random iterator
random_access_iterator_tag<RI_Type>::random_access_iterator_tag(const random_access_iterator_tag& rhd) : _ptr(rhd._ptr){};


template <typename RI_Type> //RI == Random iterator
random_access_iterator_tag<RI_Type>& random_access_iterator_tag<RI_Type>::operator=(const random_access_iterator_tag &rhd)
{
	if(this == &rhd)
		return (*this);
	this->_ptr = rhd->_ptr;
	return (*this);
}

template <typename RI_Type> //RI == Random iterator
bool random_access_iterator_tag<RI_Type>::operator==(const random_access_iterator_tag &rhd) const
{
	return (this->_ptr == rhd->_ptr);
}

template <typename RI_Type>
bool random_access_iterator_tag<RI_Type>::operator!=(const random_access_iterator_tag &rhd) const
{
	return (this->_ptr != rhd->_ptr);
}


template <typename RI_Type>
RI_Type random_access_iterator_tag<RI_Type>::operator*() const//*a
{
	return (*(this->_ptr));
}

//pointer is T*
template <typename RI_Type>
RI_Type* random_access_iterator_tag<RI_Type>::operator->() const // 잘모르겠음. 
{
		return (this->_ptr);
}

template <typename RI_Type>
random_access_iterator_tag<RI_Type>& random_access_iterator_tag<RI_Type>::operator++() //++a;
{
	++(this->_ptr);
	return(*this);
}

template <typename RI_Type>
random_access_iterator_tag<RI_Type>& random_access_iterator_tag<RI_Type>::operator--()//--a;
{
	--(this->_ptr);
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
random_access_iterator_tag<RI_Type>& random_access_iterator_tag<RI_Type>::operator--(int) //++a;
{
	random_access_iterator_tag<RI_Type> tmp(*this);
	(this->_ptr)--;
	return(tmp);
}

template <typename RI_Type>
random_access_iterator_tag<RI_Type> random_access_iterator_tag<RI_Type>::operator+(difference_type n) const
{
	return random_access_iterator_tag<RI_Type> (_ptr + n);
}
template <typename RI_Type>
random_access_iterator_tag<RI_Type> random_access_iterator_tag<RI_Type>::operator-(difference_type n) const
{
	return random_access_iterator_tag<RI_Type> (_ptr - n);
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
