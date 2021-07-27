#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#include "libft/libft.h"

int main(int args, char **argv)
{
	int how_sleep;
	how_sleep = ft_atoi(argv[1]) * 1000;
     unsigned long long db;
    struct timeval end;
    unsigned long long end_msecs_time;
    struct timeval start;
    unsigned long long start_msecs_time;

//  if (start_time == 0)
//  {
        if(gettimeofday(&(start), 0) == -1)
        {
            return (-2);
        }
        start_msecs_time = (start.tv_sec * 1000000) + (start.tv_usec);

//  }
//  else
//      start_msecs_time = (start_time);
//    while(1)
//    {
//        usleep(10);
//        if(gettimeofday(&end, 0) == -1)
//        {
//            return (-2);
//        }
//        end_msecs_time = (end.tv_sec * 1000000) + (end.tv_usec);
//        if(how_sleep <= end_msecs_time - start_msecs_time)
//            break;
//    }

		usleep(how_sleep);
        gettimeofday(&end, 0);

        end_msecs_time = (end.tv_sec * 1000000) + (end.tv_usec);

	printf("%lld\n", end_msecs_time - start_msecs_time);
	return (0);
}

