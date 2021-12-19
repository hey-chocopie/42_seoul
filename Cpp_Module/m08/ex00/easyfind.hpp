#ifndef __EASYFIND_HPP__
#define __EASYFIND_HPP__

template <typename T>
typename T::iterator easyfind(T container, int search_data)
{
	//iterator가 T의 종속이므로 typename을 앞에 붙여주어야함. 
	typename T::iterator it;
	for (it = std::begin(container); it!=std::end(container); ++it)
	{
		if(*it == search_data)
			return it;
	}
	throw std::invalid_argument("Number not found");
}

template <typename first, typename second>
typename std::map<first, second>::iterator easyfind(std::map<first, second> container, int search_data)
{
	//iterator가 map의 종속이므로 typename을 앞에 붙여주어야함. 
	typename std::map<first, second>::iterator it;
	for (it = std::begin(container); it!=std::end(container); ++it)
	{
		if(it->first == search_data)
			return it;
	}
	throw std::invalid_argument("Number not found");
}

#endif
