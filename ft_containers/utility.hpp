#ifndef __UTILITY_HPP__
#define __UTILITY_HPP__
namespace ft
{
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
