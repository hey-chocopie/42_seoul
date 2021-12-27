#ifndef __EASYFIND_HPP__
#define __EASYFIND_HPP__

# include <algorithm>

template <typename T>
typename T::iterator easyfind(T container, int search_data)
{
	//iterator가 T의 종속이므로 typename을 앞에 붙여주어야함.
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), search_data);
	if(it == container.end() )
		throw std::invalid_argument("Number not found");
	return it;
}

template <typename first, typename second>
typename std::map<first, second>::iterator easyfind(std::map<first, second> container, int search_data)
{
	//iterator가 map의 종속이므로 typename을 앞에 붙여주어야함. 
	typename std::map<first, second>::iterator it;
	it = container.find(search_data);
	if(it == container.end())
		throw std::invalid_argument("Number not found");
	return it;
}

#endif
