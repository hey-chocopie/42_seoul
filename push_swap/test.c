#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

 void        input_string(char *a, char *tmp)
 {
     int i = 0;

     while(tmp[i])
     {
         a[i] = tmp[i];
		 i++;
     }
     return ;
 }

int main(void)
{
	char *a;

	a = malloc (4);
	//free(a);
	input_string(a, "hi");
	printf("%s", a);
	printf("==%c==", a[2]);
	int i = 0;
	while(a[i] != 0)
	{
		printf("==%c==", a[i]);
		i++;
	}
	free(a);
	return 0;
}
