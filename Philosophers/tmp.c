#include <stdio.h>
#include <limits.h>

int main(void)
{
	unsigned long a;
	printf("long max = %ld\n", LONG_MAX);
	printf("long long max = %lld\n", LLONG_MAX);
	a = 9223372036854775807;
	a = a +2;
	printf("%lu", a);
	return 0;
}
