#include "iter.hpp"

int main (void)
{
	int a[4];
	for (size_t i = 0; i < 4; i++)
		a[i] = 22;
	size_t arr_size = 4;
	iter(a, arr_size, test);
	std::cout << std::endl;

	double c[4];
	for (size_t i = 0; i < 4; i++)
		c[i] = 22.2;
	arr_size = 4;
	iter(c, arr_size, test);
	std::cout << std::endl;

	float d[4];
	for (size_t i = 0; i < 4; i++)
		d[i] = 22.2;
	arr_size = 4;
	iter(d, arr_size, test);
	std::cout << std::endl;

	std::string b[4];
	for (size_t i = 0; i < 4; i++)
		b[i] = "hoylee";
	arr_size = 4;
	iter(b, arr_size, test);
}
