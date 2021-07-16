#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#include "../libft/libft.h"

typedef struct  s_time
{

	struct timeval		now;
	unsigned long long	start_msecs_time;
	unsigned long long	now_msecs_time;
}               t_time;


typedef struct  s_phil_data
{
	struct s_time	t;
}               t_phil_data;

int argv_check(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while(i < argc)
	{
		j = 0;
		while(argv[i][j])
		{
			if(ft_isdigit(argv[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int argc_argv_check(int argc, char **argv)
{
	if(argc != 5 && argc != 6)
	{
		printf("please check argc");
		return (-1);
	}
	if(argv_check(argc, argv) == 0)
	{
		printf("argv is can't not number");
		return (-1);
	}
	return (0);
}

int		accurate_usleep(t_phil_data *pd, unsigned long long how_sleep)
{
	struct timeval end;
	unsigned long long end_msecs_time;
	
	if(gettimeofday(&(pd->t.now), 0) == -1)
	{
		printf("time error");
		return (-1);
	}
	pd->t.now_msecs_time = (pd->t.now.tv_sec * 1000000) + (pd->t.now.tv_usec);
	while(1)
	{
		usleep(20);
		if(gettimeofday(&end, 0) == -1)
		{
			printf("time error");
			return (-1);
		}
		end_msecs_time = (end.tv_sec * 1000000) + (end.tv_usec);
		if(how_sleep <= end_msecs_time - pd->t.now_msecs_time)
			break;
	}
	return (0);
}

int		time_distinction_start_between_end(t_phil_data *pd)
{
	struct timeval end;
	unsigned long long end_msecs_time;

	if(gettimeofday(&end, 0) == -1)
		return -1;
	end_msecs_time = (end.tv_sec * 1000000) + (end.tv_usec);
	printf("how == %llu\n", end_msecs_time / 1000 - pd->t.start_msecs_time / 1000);
	return (0);
}

int main(int argc, char **argv)
{
	//뭐하고 있었냐면 구조체형태로 바꾸고 있었음.
	// start는 구조체에 넣으면 좋잖아? 
	struct timeval mytime;
	t_phil_data pd;

	if(argc_argv_check(argc, argv) == -1)
		return (-1);
	printf("ok");
	if(gettimeofday(&mytime, 0) == -1)
	{
		printf("time error");
		return (-1);
	}
	pd.t.start_msecs_time = (mytime.tv_sec * 1000000) + (mytime.tv_usec);
	usleep(5000);

	time_distinction_start_between_end(&pd);
	if (accurate_usleep(&pd, 5000) == -1 || time_distinction_start_between_end(&pd) == -1)
	{
		printf("time error");
		return (-1);
	}
	return (0);
}
