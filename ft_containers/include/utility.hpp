#ifndef __UTILITY_HPP__
#define __UTILITY_HPP__
namespace ft
{
	//=======================Mycustom_funtion=====================

	size_t increase_capacity(size_t _size, size_t n, size_t _capacity)
	{
	    if(_capacity == 0)
	        _capacity = 1;
	    while(_size + n >= _capacity)
	        _capacity = _capacity * 2;
	    return _capacity;
	}

	template <typename size_type, typename value_type, typename Alloc>
	void Array_clear_free(size_type &_size, size_type &_capacity, value_type** _array, Alloc _alloc)
	{
		if ((*_array) != NULL)
		{
			for (size_t i = 0; i < _size; ++i)
				_alloc.destroy((*_array) + i);
			_alloc.deallocate((*_array), _capacity);
			(*_array) = 0;
			_size = 0;
			_capacity = 0;
		}
	}

	//default (1)	
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2)
	{
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1) return false;
			else if (*first1<*first2) return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	}
	//custom (2)	
	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2,
								Compare comp)
	{
		while (first1 != last1) {
			if (first2 == last2 || comp(*first2, *first1)) return false;
			else if (comp(*first1, *first2)) return true;
			++first1; ++first2;
		}
		return (first2 != last2);
	}

	template <class InputIterator1, class InputIterator2>
	bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
	{
		while (first1!=last1) {
			if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
				return false;
			++first1; ++first2;
		}
		return true;
	}
}

#endif
