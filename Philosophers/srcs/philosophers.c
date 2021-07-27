#include "../include/philosophers.h"

//typedef struct  s_time
//{
//	struct timeval		start;
//	struct timeval		now;
//	unsigned long long	start_msecs_time;
//	unsigned long long	now_msecs_time;
//	unsigned long long	*last_eat_time;
//}               t_time;
//
//typedef struct  s_philosophers_data
//{
//	int		number_of_philosophers;
//	int		time_to_die;
//	int		time_to_eat;
//	int		time_to_sleep;
//	int		number_of_times_each_philosopher_must_eat;
//}               t_philosopers_data;
//
//typedef struct  s_all_data
//{
//	int				number;
//	pthread_mutex_t *mutex;
//	pthread_mutex_t *monitor_mutex;
//	pthread_t		*philosopher;
//	pthread_t		*monitor;
//	struct s_philosophers_data pd;
//	struct s_time	t;
//	int				*die_flag;
//}               t_all_data;

void *t_monitor(void * arg)
{
	t_all_data *ad = (t_all_data *)arg;

	while(1)
	{
		pthread_mutex_lock(ad->monitor_mutex);
		get_time(&ad->t.now_msecs_time);
		if (*(ad->die_flag) == 1)
		{
			pthread_mutex_unlock(ad->monitor_mutex);
			break;
		}
		if(((ad->t.now_msecs_time - ad->t.last_eat_time[ad->number]) / 1000) > ad->pd.time_to_die)
		{
			*(ad->die_flag) = 1;
			*(ad->die_index) = ad->number;
			pthread_mutex_unlock(ad->monitor_mutex);
			time_distinction_start_between_end(ad, "die flag <------1-----", ad->number);
			break;
		}
		else
			pthread_mutex_unlock(ad->monitor_mutex);
		usleep(1000);
	}
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
	if(0 == (ad->t.last_eat_time =  malloc(ad->pd.number_of_philosophers * sizeof(unsigned long long))))
		return (-3);
	if(0 == (ad->die_flag = malloc(sizeof(int))))
		return (-3);

	if(0 == (ad->die_index = malloc(sizeof(int))))
		return (-3);

//	if(0 == (ad->t.end_msecs_time =  malloc(ad->pd.number_of_philosophers * sizeof(unsigned long long))))
//return (-3);
//	if(0 == (ad->t.new_msecs_time =  malloc(ad->pd.number_of_philosophers * sizeof(unsigned long long))))
//		return (-3);
//
//
//	if(0 == (ad->t.end =  malloc(ad->pd.number_of_philosophers * sizeof(struct timeval))))
//		return (-3);
//	if(0 == (ad->t.new_time =  malloc(ad->pd.number_of_philosophers * sizeof(struct timeval))))
//		return (-3);
//  추가됨 프리해줄것.
	//if(0 == (ad->p_status = malloc(sizeof(char *) * ad->pd.number_of_philosophers)))
//		return (-3);
	//if(0 == (ad->status_flag = malloc(sizeof(int))))
//		return (-3);
	//*(ad->status_flag) = 0;

	*(ad->die_flag) = 0;
	*(ad->die_index) = -1;
	return (0);


}

int		make_philosophers_thread_and_monitor_thread(t_all_data *ad, t_all_data **tmp)
{
	int i;
	int thr_id;
	int m_thr_id;

	i = 0;
	while(i < ad->pd.number_of_philosophers)
	{
//		if(i % 2 == 0 && i != ad->pd.number_of_philosophers - 1)
//		{
			(*tmp)[i] = *ad;
			(*tmp)[i].number = i;
			thr_id = pthread_create(&ad->philosopher[i], NULL, t_philo_thread, (&((*tmp)[i])));
			m_thr_id = pthread_create(&ad->monitor[i], NULL, t_monitor, (&((*tmp)[i])));
			if(thr_id < 0 || m_thr_id < 0)
			{
				return (-5);
			}
//		}
		i++;
    }
	i = 0;
	//usleep(20);
//	while(i < ad->pd.number_of_philosophers)
//	{
//		if(i % 2 == 1)
//		{
//			(*tmp)[i] = *ad;
//			(*tmp)[i].number = i;
//			thr_id = pthread_create(&ad->philosopher[i], NULL, t_philo_thread, (&((*tmp)[i])));
//			m_thr_id = pthread_create(&ad->monitor[i], NULL, t_monitor, (&((*tmp)[i])));
//			if(thr_id < 0 || m_thr_id < 0)
//			{
//				return (-5);
//			}
//		}
//		i++;
//    }
//	//usleep(20);
//	if(ad->pd.number_of_philosophers % 2 == 1)
//	{
//		(*tmp)[ad->pd.number_of_philosophers - 1] = *ad;
//		(*tmp)[ad->pd.number_of_philosophers - 1].number = ad->pd.number_of_philosophers - 1;
//		thr_id = pthread_create(&ad->philosopher[ad->pd.number_of_philosophers - 1], NULL, t_philo_thread, (&((*tmp)[ad->pd.number_of_philosophers - 1])));
//		m_thr_id = pthread_create(&ad->monitor[ad->pd.number_of_philosophers - 1], NULL, t_monitor, (&((*tmp)[ad->pd.number_of_philosophers - 1])));
//			if(thr_id < 0 || m_thr_id < 0)
//			{
//				return (-5);
//			}
//	}
	return (0);
}

int		create_thread(t_all_data *ad, t_all_data **tmp)
{
	int i;

	if((i = malloc_set(ad, tmp)) < 0)
		return (i);
	i = -1;
	while(++i < ad->pd.number_of_philosophers)
			if(get_time(&(ad->t.last_eat_time[i])) == -2)
				return (-2);
	i = -1;

//	while(++i < ad->pd.number_of_philosophers)
//		ad->p_status[i] = "thinking";
//	while(++i < ad->pd.number_of_philosophers)
//		if(i % 2 == 0 && i != ad->pd.number_of_philosophers - 1)
//		{
//			if(get_time(&(ad->t.last_eat_time[i])) == -2)
//				return (-2);
//		}
//	i = -1;
//	usleep(50);
//	while(++i < ad->pd.number_of_philosophers)
//		if(i % 2 == 1)
//		{
//			if(get_time(&(ad->t.last_eat_time[i])) == -2)
//				return (-2);
//		}
//	usleep(50);
//	if(ad->pd.number_of_philosophers % 2 == 1)
//	{
//		if(get_time(&(ad->t.last_eat_time[ad->pd.number_of_philosophers - 1])) == -2)
//			return (-2);
//	}
	if(make_philosophers_thread_and_monitor_thread(ad, tmp) == -5)
		return (-5);
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

	ad->die_index = 0;
	ad->print_mutex = 0;
}

void	error_print(t_all_data *ad ,int error_code)
{
	if(error_code == -1)
		printf("arguments error!\n");
	else if(error_code == -2)
		printf("gettimeofday error!\n");
	else if(error_code == -3)
		printf("malloc error!\n");
	else if(error_code == -4)
		printf("pthread_mutex_init error!\n");
	else if(error_code == -5)
		printf("thread create error\n");
}


int main(int argc, char **argv)
{
	int i;
	void *status;
	void *st2;
	int error_code;

	t_all_data *tmp;
	t_all_data	ad;
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
	i = -1;
	while (++i < ad.pd.number_of_philosophers)
	{
        pthread_join(ad.philosopher[i], (void **)&status);
		if((int)(status) < 0)
			printf("hahaha");
        pthread_join(ad.monitor[i], (void **)&status);
if((int)(status) < 0)
	printf("hahaha");

		//		printf("%d ", i);
//		printf("%d\n", (int)(status));

	}
	if(*(ad.die_index) != -1)
		time_distinction_start_between_end(&ad, "die flag <-----------", *(ad.die_index));
//	i = -1;
//	while (++i < ad.pd.number_of_philosophers)
//	{
//		usleep(50);
//		printf("==%d, %d\n", status, i);
//		usleep(50);
//	}
	all_free(&ad, &tmp);
	return (0);
}
