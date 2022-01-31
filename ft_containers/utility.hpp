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
	void Array_clear_free(size_type &_size, size_type &_capacity, value_type* _array, Alloc _alloc)
	{
		if (_array)
		{
			for (size_t i = 0; i < _size; ++i)
				_alloc.destroy(_array + i);
			_alloc.deallocate(_array, _capacity);
			_array = 0;
		}
	}

	template <class L_vector, class R_vector>
	bool equal_check(L_vector& lhs, R_vector& rhs) //==
	{
	    if (lhs.size() != rhs.size())
	        return (false);
	    for (size_t i = 0; i < lhs.size(); i++)
	        if (lhs._array[i] != rhs._array[i])
	            return (false);
	    return (true);
	}
	template <class L_vector, class R_vector>
	bool right_compare_check(L_vector& lhs, R_vector& rhs) //<
	{
	    for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
	        if (lhs._array[i] < rhs._array[i])
	            return (true);
	        else if(lhs._array[i] > rhs._array[i])
	            return (false);
	    return ((lhs.size() < rhs.size()) ? true : false);
	}
	template <class L_vector, class R_vector>
	bool left_compare_check(L_vector& lhs, R_vector& rhs) //>
	{
	    for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
	        if (lhs._array[i] > rhs._array[i])
	            return (true);
	        else if(lhs._array[i] < rhs._array[i])
	            return (false);
	    return ((lhs.size() > rhs.size()) ? true : false);
	}
	template <class L_vector, class R_vector, typename Func>
	bool all_check(L_vector& lhs, R_vector& rhs, Func ((left_or_right))) //<=
	{
	    if (equal_check(lhs, rhs) == 1)
	        return (true);
	    if (left_or_right(lhs, rhs) == 1)
	        return (true);
	    return (false);
	 }
}

#endif
