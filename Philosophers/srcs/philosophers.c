#include "../include/philosophers.h"

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
		(*tmp)[i] = *ad;
		(*tmp)[i].number = i;
		thr_id = pthread_create(&ad->philosopher[i], NULL, t_philo_thread, (&((*tmp)[i])));
		m_thr_id = pthread_create(&ad->monitor[i], NULL, t_monitor, (&((*tmp)[i])));
		if(thr_id < 0 || m_thr_id < 0)
		{
			return (-5);
		}
		i++;
    }
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
	if (ad->print_mutex != 0)
		free(ad->print_mutex);
	if (ad->philosopher != 0)
		free(ad->philosopher);
	if (ad->monitor != 0)
		free(ad->monitor);
	if (ad->t.last_eat_time != 0)
		free(ad->t.last_eat_time);
	if (ad->die_flag != 0)
		free(ad->die_flag);
	if (ad->die_index != 0)
		free(ad->die_index);
	if (*tmp != 0)
		free(*tmp);

}

void malloc_reset(t_all_data *ad, t_all_data **tmp)
{
	ad->mutex = 0;
	ad->monitor_mutex = 0;
	ad->print_mutex = 0;
	ad->philosopher = 0;
	ad->monitor = 0;
	ad->t.last_eat_time = 0;
	ad->die_flag = 0;
	ad->die_index = 0;
	*tmp = 0;
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
