#include "../include/philo.h"

void	check_number_print(int number, char *action_string)
{
	if (number == -1)
		printf(" %s\n", action_string);
	else
		printf(" %d %s\n", number, action_string);
}

int	print_t_data(t_all_data *ad, char *action_string, int number)
{
	struct timeval		end;
	unsigned long long	end_msecs_time;

	pthread_mutex_lock(ad->monitor_mutex);
	if (*(ad->die_flag) == 1 || *(ad->die_flag) == 2)
	{
		if (*(ad->die_flag) == 1)
			*(ad->die_flag) = 2;
		else
		{
			pthread_mutex_unlock(ad->monitor_mutex);
			return (1);
		}
	}
	if (gettimeofday(&end, 0) == -1)
		return (-2);
	end_msecs_time = (end.tv_sec * 1000000) + (end.tv_usec);
	printf("%llu", end_msecs_time / 1000 - ad->t.start_msecs_time / 1000);
	check_number_print(number, action_string);
	pthread_mutex_unlock(ad->monitor_mutex);
	if (*(ad->die_flag) == 2)
		return (1);
	return (0);
}

int	accurate_usleep(unsigned long long how_sleep, unsigned long long start_time)
{
	struct timeval		end;
	unsigned long long	end_msecs_time;
	struct timeval		start;
	unsigned long long	start_msecs_time;

	if (start_time == 0)
	{
		if (gettimeofday(&(start), 0) == -1)
		{
			return (-2);
		}
		start_msecs_time = (start.tv_sec * 1000000) + (start.tv_usec);
	}
	else
		start_msecs_time = start_time;
	while (1)
	{
		usleep(100);
		if (gettimeofday(&end, 0) == -1)
			return (-2);
		end_msecs_time = (end.tv_sec * 1000000) + (end.tv_usec);
		if (how_sleep <= end_msecs_time - start_msecs_time)
			break ;
	}
	return (0);
}
