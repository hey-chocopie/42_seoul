#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "easyfind.hpp"

int main(void)
{
	//c++ 98 STL 컨테이너 종류 : deque, list, map, queue, set, stack, vector
	try{
	std::cout << "==========deque========="<< std::endl;
	std::deque<int> d_data;
	d_data.push_back(1);
	d_data.push_back(2);
	d_data.push_back(3);
	std::deque<int>::iterator d_iter = easyfind(d_data, 3);
	std::cout << *d_iter << std::endl;
	}
	catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

	try{
	std::cout << "==========list========="<< std::endl;
	std::list<int> l_data;
	l_data.push_back(1);
	l_data.push_back(2);
	l_data.push_back(3);
	std::list<int>::iterator l_iter = easyfind(l_data, 3);
	std::cout << *l_iter << std::endl;
	}
	catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
	
	try{
	std::cout << "==========map========="<< std::endl;
	std::map<int, string> m_data;
	m_data[1] = "hoylee1";
	m_data[2] = "hoylee2";
	m_data[3] = "hoylee3";

	std::map<int, string>::iterator m_iter = easyfind(m_data, 3);
	std::cout << *d_iter << std::endl;
	}
	catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

	try{
	std::cout << "==========vector========="<< std::endl;
	std::vector<int> v_data;
	v_data.push_back(1);
	v_data.push_back(2);
	v_data.push_back(3);
	std::vector<int>::iterator v_iter = easyfind(v_data, 3);
	std::cout << *v_iter << std::endl;
	
	}
	catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
	return 0;
}
