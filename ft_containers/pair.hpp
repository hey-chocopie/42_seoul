#ifndef __PAIR_HPP__
#define __PAIR_HPP__

namespace ft{
	template <class T1, class T2>
	struct pair{
	public:
		//===========================Member types=======================
		typedef T1								first_type
		typedef T2								second_type

		first_type								first;
		second_type								second;

		//===========================construct=======================
		//default (1)
		pair();
		//copy (2)
		template<class U, class V> pair (const pair<U,V>& pr);
		//initialization (3)
		pair (const first_type& a, const second_type& b);

		pair& operator= (const pair& pr);


	}
	template <class T1, class T2>
	pair<T1, T2>::pair() : first(), second() {}
	
	template <class T1, class T2>
	template<class U, class V>
	pair<T1, T2>::pair(const pair<U,V>& pr) : first(pr.first), second(pr.second) {}
	
	template <class T1, class T2>
	pair<T1, T2>::pair (const first_type& a, const second_type& b) : first(a), second(b) {}
	
	template <class T1, class T2>
	pair<T1, T2>& pair<T1, T2>::operator= (const pair& pr)
	{
		first = pr.first;
		second = pr.second;
		return (*this);
	}

	//===========================Non-member function overloads=======================
	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return ((lhs.first == rhs.first) && (lhs.second == rhs.second)) }
	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs == rhs) }
	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }
	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(rhs<lhs); }
	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return rhs<lhs; }
	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs<rhs); }

	//===========================See also=======================
	template <class T1, class T2>
	ft::pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return ( pair<T1,T2>(x,y) );
	}
}

#endif
