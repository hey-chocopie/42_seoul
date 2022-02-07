#include <iostream>
#include <map>
#include <vector>
#include "pair.hpp"
#include "map.hpp"
int main(void){
	std::vector<ft::pair<int, int> > data;
	data.push_back(ft::make_pair(50,2));
	data.push_back(ft::make_pair(100,3));
	data.push_back(ft::make_pair(2000,4));

	ft::map<int, int> why(data.begin(), data.end());

	return 0;
}
