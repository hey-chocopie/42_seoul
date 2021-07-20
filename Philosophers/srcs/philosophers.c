#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#include "../libft/libft.h"

typedef struct  s_time
{
	struct timeval		start;
	struct timeval		now;
	unsigned long long	start_msecs_time;
	unsigned long long	now_msecs_time;
	unsigned long long	*last_eat_time;
}               t_time;

typedef struct  s_philosophers_data
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
}               t_philosopers_data;

typedef struct  s_all_data
{
	int				number;
	pthread_mutex_t *mutex;
	pthread_mutex_t *monitor_mutex;
	pthread_t		*philosopher;
	pthread_t		*monitor;
	struct s_philosophers_data pd;
	struct s_time	t;
	int				*die_flag;
}               t_all_data;

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
		return (-1);
	if(argv_check(argc, argv) == 0)
		return (-1);
	return (0);
}

int		accurate_usleep(unsigned long long how_sleep)
{
	struct timeval end;
	unsigned long long end_msecs_time;
	struct timeval start;
	unsigned long long start_msecs_time;
	if(gettimeofday(&(start), 0) == -1)
	{
		printf("time error");
		return (-1);
	}
	start_msecs_time = (start.tv_sec * 1000000) + (start.tv_usec);
	while(1)
	{
		usleep(20);
		if(gettimeofday(&end, 0) == -1)
		{
			printf("time error");
			return (-1);
		}
		end_msecs_time = (end.tv_sec * 1000000) + (end.tv_usec);
		if(how_sleep <= end_msecs_time - start_msecs_time)
			break;
	}
	return (0);
}

int get_time(unsigned long long *save)
{
	struct timeval now;

	if(gettimeofday(&now, 0) == -1)
		return (-2);
	*save = (now.tv_sec * 1000000) + (now.tv_usec);
	return (0);
}

int		time_distinction_start_between_end(t_all_data *ad, char *action_string, int number)
{
	struct timeval end;
	unsigned long long end_msecs_time;

	if(gettimeofday(&end, 0) == -1)
		return -1;
	end_msecs_time = (end.tv_sec * 1000000) + (end.tv_usec);
	printf("%llu", end_msecs_time / 1000 - ad->t.start_msecs_time / 1000);
	printf(" %d %s\n",  number, action_string);
	return (0);
}

int		set_philosopers(int argc, char **argv, t_all_data *ad)
{
	int		i;
	int		tmp;
	int		numbers;

	i = 1;
	ad->pd.number_of_times_each_philosopher_must_eat = -1;
	while(i < argc)
	{
		tmp = ft_atoi(argv[i]);
		if (tmp <= 0 || (tmp == 1 && i == 1))
			return (-1);
		if (i == 1)
			ad->pd.number_of_philosophers = tmp;
		else if (i == 2)
			ad->pd.time_to_die = tmp;
		else if (i == 3)
			ad->pd.time_to_eat = tmp;
		else if (i == 4)
			ad->pd.time_to_sleep = tmp;
		else if (i == 5)
			ad->pd.number_of_times_each_philosopher_must_eat = tmp;
		i++;
	}
	return (0);
}

void *t_zzak(void * arg)
{
	int philosopher_number;
	int philosopher_next_number;
	int philosopher_pre_number;
	t_all_data *ad = (t_all_data *)arg;


	philosopher_number = ad->number;
	philosopher_next_number = (ad->number + 1) % (ad->pd.number_of_philosophers + 1);
	if((philosopher_number - 1) == -1)
		philosopher_pre_number = (ad->pd.number_of_philosophers - 1);
	else
		philosopher_pre_number = philosopher_number - 1;

	if(ad->number % 2 == 1)
		usleep(5);
	if(ad->pd.number_of_philosophers % 2 == 1)
		if (ad->pd.number_of_philosophers == ad->number + 1)
			usleep(20);
	while(1)
	{
		if(ad->number % 2 == 1)
		{
			pthread_mutex_lock(&(ad->mutex[philosopher_number])); //먼저 다 락떄려
			time_distinction_start_between_end(ad, "has taken a fork", philosopher_number);
			pthread_mutex_lock(&(ad->mutex[philosopher_pre_number])); //먼저 다 락떄려
			time_distinction_start_between_end(ad, "has taken a fork", philosopher_number);
		}
		else if(ad->number % 2 == 0)
		{
			if(ad->pd.number_of_philosophers % 2 == 1)
			{
				if(ad->t.last_eat_time[philosopher_number] >= 1000)
					usleep(100);
			}
			pthread_mutex_lock(&(ad->mutex[philosopher_pre_number])); //먼저 다 락떄려
			time_distinction_start_between_end(ad, "has taken a fork", philosopher_number);
			pthread_mutex_lock(&(ad->mutex[philosopher_number])); //먼저 다 락떄려
			time_distinction_start_between_end(ad, "has taken a fork", philosopher_number);
		}

		pthread_mutex_lock(ad->monitor_mutex); //먼저 다 락떄려
		get_time(&(ad->t.last_eat_time[philosopher_number]));
		pthread_mutex_unlock(ad->monitor_mutex); //먼저 다 락떄려
		if (time_distinction_start_between_end(ad, "is eating", philosopher_number) == -1 || (accurate_usleep(1000 * ad->pd.time_to_eat)) == -1)
		{
			printf("time error");
			//return (-1);
		}
		//time_distinction_start_between_end(ad, "test test", philosopher_number);
		pthread_mutex_unlock(&(ad->mutex[philosopher_number])); //먼저 다 락떄려
		pthread_mutex_unlock(&(ad->mutex[philosopher_pre_number])); //먼저 다 락떄려
		if(*(ad->die_flag) == 1)
			break;
		if (time_distinction_start_between_end(ad, "is sleeping", philosopher_number) == -1 || (accurate_usleep((1000 * ad->pd.time_to_sleep))) == -1 )
		{
			printf("time error");
			//return (-1);
			//따로 해야할듯...
		}
		if(time_distinction_start_between_end(ad, "is thinking", philosopher_number) == -1)
		{
			printf("time error");
			//return (-1);
		}
	}
	return (0);
}


int		create_mutex(t_all_data *ad)
{
	int i = 0;
	
	if(0 == (ad->mutex = malloc(ad->pd.number_of_philosophers * sizeof(pthread_mutex_t))))
		return (-3);
	if(0 == (ad->monitor_mutex = malloc(sizeof(pthread_mutex_t))))
		return (-3);
	while(i < ad->pd.number_of_philosophers)
	{
		if(pthread_mutex_init(&ad->mutex[i], NULL) == -1)
			return (-4);
		i++;
    }
	if(pthread_mutex_init(ad->monitor_mutex, NULL) == -1)
		return (-4);
	return 0;
}

void *t_monitor(void * arg)
{
	int philosopher_number;
	int philosopher_pre_number;
	int philosopher_next_number;

	t_all_data *ad = (t_all_data *)arg;


//	philosopher_number = ad->number;
//	philosopher_next_number = (ad->number + 1) % (ad->pd.number_of_philosophers + 1);
//	if((philosopher_number - 1) == -1)
//		philosopher_pre_number = (ad->pd.number_of_philosophers - 1);
//	else
//		philosopher_pre_number = philosopher_number - 1;
	while(1)
	{
		pthread_mutex_lock(ad->monitor_mutex); //먼저 다 락떄려
		get_time(&ad->t.now_msecs_time);
		if(*(ad->die_flag) == 1 || ((ad->t.now_msecs_time - ad->t.last_eat_time[ad->number]) / 1000) > ad->pd.time_to_die)
		{
			*(ad->die_flag) = 1;
			printf("%d die flag\n", ad->number);
			break;
		}
		pthread_mutex_unlock(ad->monitor_mutex); //먼저 다 락떄려
		usleep(50);
	}
	pthread_mutex_unlock(ad->monitor_mutex); //먼저 다 락떄려

//	while(1)
//	{
//		//pthread_mutex_lock(&(ad->monitor_mutex)); //먼저 다 락떄려
//		if(ft_strncmp(ad->philosopher_status[philosopher_number], "thinking", 9) == 0 && (ft_strncmp(ad->philosopher_status[philosopher_next_number], "thinking", 9) == 0  || ft_strncmp(ad->philosopher_status[philosopher_next_number], "sleeping", 9)) && (ft_strncmp(ad->philosopher_status[philosopher_pre_number], "thinking", 9) == 0 || ft_strncmp(ad->philosopher_status[philosopher_next_number], "sleeping", 9)))
//		{
//			ad->philosopher_status[philosopher_number] = "eating";
//			pthread_mutex_unlock(&(ad->mutex[ad->number]));
//		}
//		pthread_mutex_unlock(&(ad->monitor_mutex)); //먼저 다 락떄려
//		usleep(50);
//	}
	return 0;
}

int		malloc_set(t_all_data *ad, t_all_data **tmp)
{
	if(0 == ((*tmp) = malloc(ad->pd.number_of_philosophers * sizeof(t_all_data))))
		return (-3);
	if(0 == (ad->philosopher = malloc(ad->pd.number_of_philosophers * sizeof(pthread_t))))
		return (-3);
	if(0 == (ad->monitor = malloc(ad->pd.number_of_philosophers * sizeof(pthread_t))))
		return (-3);
	if(0 == (ad->t.last_eat_time =  malloc(ad->pd.number_of_philosophers * sizeof(unsigned long long *))))
		return (-3);
	if(0 == (ad->die_flag = malloc(sizeof(int))))
		return (-3);
	*(ad->die_flag) = 0;
	return (0);
}

int		create_thread(t_all_data *ad, t_all_data **tmp)
{
	int i;
	int thr_id;
	int m_thr_id;

	if((i = malloc_set(ad, tmp)) < 0)
		return (i);
	i = -1;
	while(++i < ad->pd.number_of_philosophers)
		get_time(&(ad->t.last_eat_time[i]));
	i = 0;
	while(i < ad->pd.number_of_philosophers)
	{
		(*tmp)[i] = *ad;
		(*tmp)[i].number = i;
//		if(i % 2 == 0)
		thr_id = pthread_create(&ad->philosopher[i], NULL, t_zzak, (&((*tmp)[i])));
//		if(i % 2 == 1)
//			thr_id = pthread_create(&ad->philosopher[i], NULL, t_hole, (&(tmp[i])));
		m_thr_id = pthread_create(&ad->monitor[i], NULL, t_monitor, (&((*tmp)[i])));
		if(thr_id < 0 || m_thr_id < 0)
		{
			perror("thread create error : ");
			exit(0);
		}
		i++;
    }
	return (0);
}

void	all_free(t_all_data *ad, t_all_data **tmp)
{
	if (ad->mutex != 0)
		free(ad->mutex);
	if (ad->monitor_mutex != 0)
		free(ad->monitor_mutex);
	if (ad->philosopher != 0)
		free(ad->philosopher);
	if (ad->monitor != 0)
		free(ad->monitor);
	if (ad->t.last_eat_time != 0)
		free(ad->t.last_eat_time);
	if (ad->die_flag != 0)
		free(ad->die_flag);
	if (*tmp != 0)
		free(*tmp);

}

void malloc_reset(t_all_data *ad, t_all_data **tmp)
{
	ad->mutex = 0;
	ad->monitor_mutex = 0;
	ad->philosopher = 0;
	ad->monitor = 0;
	ad->t.last_eat_time = 0;
	ad->die_flag = 0;
	*tmp = 0;
}
void	error_print(t_all_data *ad ,int error_code)
{
	if(error_code == -1)
		printf("arguments error!");
	else if(error_code == -2)
		printf("gettimeofday error!");
	else if(error_code == -3)
		printf("malloc error!");
	else if(error_code == -4)
		printf("pthread_mutex_init error!\n");
}


int main(int argc, char **argv)
{
	//뭐하고 있었냐면 구조체형태로 바꾸고 있었음.
	// start는 구조체에 넣으면 좋잖아? 
	t_all_data	ad;
	int i;
	int error_code;
	t_all_data *tmp;
	malloc_reset(&ad, &tmp);
	if((error_code = argc_argv_check(argc, argv)) < 0 ||
	(error_code = set_philosopers(argc, argv, &ad)) < 0 ||
	(error_code = get_time(&ad.t.start_msecs_time)) < 0 ||
	(error_code = create_mutex(&ad)) < 0 ||
	(error_code = create_thread(&ad, &tmp)) < 0)
	{
		error_print(&ad , error_code);
		all_free(&ad, &tmp);
		return (-1);
	}
	i = 0;
	while (i < ad.pd.number_of_philosophers)
	{
        pthread_join(ad.philosopher[i], NULL);
		i++;
	}
	all_free(&ad, &tmp);
	return (0);
}
