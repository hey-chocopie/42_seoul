#include "iter.hpp"

int main (void)
{
	int a[4];
	for (int i = 0; i < 4; i++)
		a[i] = 22;
	iter(a, 4, test);
	std::cout << std::endl;

	double c[4];
	for (int i = 0; i < 4; i++)
		c[i] = 22.2;
	iter(c, 4, test);
	std::cout << std::endl;

	float d[4];
	for (int i = 0; i < 4; i++)
		d[i] = 22.2;
	iter(d, 4, test);
	std::cout << std::endl;

	std::string b[4];
	for (int i = 0; i < 4; i++)
		b[i] = "hoylee";
	iter(b, 4, test);
}
