#include "vector.hpp"
#include <vector>
int main(void)
{
	ft::vector<int> a;
	ft::vector<int> b(55);

	std::vector<int> ss(4, 55);
	ft::vector<int> c(ss.begin(), ss.end());
	std::cout << *c.iterator << std::endl;
	return(0);
}
