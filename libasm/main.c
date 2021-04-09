#include "libasm.h"
#include <errno.h>
#include <string.h>
#define BUFF_SIZE 2000

//int ft_len(char *a)
//{
//	int i = 0;
//	while(a[i])
//	{
//		i++;
//	}
//	return i;
//}

int main(void)
{
//	// ft_strlen
//	char s[15] =  "i'm hoylee";
//	printf("%ld\n", strlen(s));
//	printf("%ld\n", ft_strlen(s));

//	// ft_strcpy
//	char *s = malloc(sizeof(char) * 15);
//	char *s2 = malloc(sizeof(char) * 15);
//	char a[15] = "I'm hoylee";
//	ft_strcpy(s2, a); strcpy(s, a);
//	printf("input = %s, ft_strcpy == %s, strcpy == %s\n",a, s2, s);

//	// ft_strcmp
//	printf("%d, %d\n" ,strcmp("", ""), ft_strcmp("", ""));
//	printf("%d, %d\n" ,strcmp("hh", "hh"), ft_strcmp("hh", "hh"));
//	printf("%d, %d\n" ,strcmp("hhi", "hh"), ft_strcmp("hhi", "hh"));

// ft_wirte	
//	int test = 0;
//	int fd = 0;
//	char buf[1000];
//	printf("please input string : ");
//	if(0 >= scanf("%s", buf))
//	{
//		printf("check ur input valuea\n");
//		return -1;
//	}
//	if((fd = open("myfile.txt", O_RDWR | O_APPEND)) == -1)
//	{
//		printf("open_error");
//		return -1;
//	}
//	if((test = ft_write(fd, buf, ft_len(buf))) == -1)
//	{
//		printf("write_error");
//		printf("errno : %d\nError description : %s \n", errno, strerror(errno));
//		return -1;
//	}
//	printf("\"%s\" is input complete\nreturn value == %d", buf, test);
//	close(fd);

//	int a, b;
//	a = ft_write(1, "hi", 4); // 여기 왜 3 넣으면 안됨?
//	b = write(1, "hi", 4);
//	printf("\n %d, %d\n", a, b);
//	ft_write(1, "hi", 1);


// ft_reada
//	char buf[BUFF_SIZE]; //BUFF_SIZE == 2000
//	int fd = 0;
//	if (0 < ( fd = open( "myfile.txt", O_RDONLY)))
//	{
//	   if(-1 == read(fd, buf, BUFF_SIZE))
//		{
//			printf("read_error");
//			printf("errno : %d\nError description : %s \n", errno, strerror(errno));
//			close(fd);
//			return -1;
//		}
//	   close(fd);
//	}
//	else
//	{
//	   printf("파일 열기에 실패했습니다.\n");
//	}
//	printf("read value : %s", buf);

 //ft_strdup
//	char temp[20] = "hihi\0";
//	char *save;
//	char *ft_save;
//	save = strdup(temp);
//	printf("\n%s\n", save);
//	ft_save = ft_strdup(temp);
//	printf("\n%s\n", ft_save);
	return 0;
}
