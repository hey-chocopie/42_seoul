#include "../include/philosophers.h"

void	set_around_number(t_all_data *ad, int *philosopher_number, int *philosopher_next_number, int *philosopher_pre_number)
{
    *philosopher_number = ad->number;
    *philosopher_next_number = (ad->number + 1) % (ad->pd.number_of_philosophers);
    if((*philosopher_number - 1) == -1)
        *philosopher_pre_number = (ad->pd.number_of_philosophers - 1);
    else
        *philosopher_pre_number = *philosopher_number - 1;
}

void philosophers_order(t_all_data *ad)
{
    if(ad->number % 2 == 1)
		accurate_usleep(1000 * ad->pd.time_to_eat, 0);
    if(ad->pd.number_of_philosophers % 2 == 1)
        if (ad->pd.number_of_philosophers == ad->number + 1)
		accurate_usleep(1000 * ad->pd.time_to_eat * 2, 0);
}

int unlock_get_fork_error(t_all_data *ad, int return_value,int *philosopher_number, int *philosopher_pre_number)
{
	if (return_value / 10000 != 0)
	{
	    pthread_mutex_unlock(&(ad->mutex[*philosopher_pre_number]));
	    pthread_mutex_unlock(&(ad->mutex[*philosopher_number]));
		return(return_value / 10000);
	}
	else if (return_value / 1000 != 0)
	{
	    pthread_mutex_unlock(&(ad->mutex[*philosopher_pre_number]));
		return(return_value / 1000);
	}
	else if(return_value / 100 != 0)
	{
	    pthread_mutex_unlock(&(ad->mutex[*philosopher_number]));
	    pthread_mutex_unlock(&(ad->mutex[*philosopher_pre_number]));
		return(return_value / 100);
	}
	if(return_value / 10 != 0)
	{
	    pthread_mutex_unlock(&(ad->mutex[*philosopher_number]));
		return (return_value / 10);
	}
	return (0);
}

int	get_fork(t_all_data *ad, int *philosopher_number, int *philosopher_next_number, int *philosopher_pre_number)
{
	int return_value;

	if(ad->number % 2 == 1)
	{
	    pthread_mutex_lock(&(ad->mutex[*philosopher_number]));
	    if((return_value = time_distinction_start_between_end(ad, "has taken a fork", *philosopher_number)) != 0)
			return (unlock_get_fork_error(ad, return_value * 10, philosopher_number, philosopher_pre_number));
	    pthread_mutex_lock(&(ad->mutex[*philosopher_pre_number]));
	    if((return_value = time_distinction_start_between_end(ad, "has taken a fork", *philosopher_number)) != 0)
			return (unlock_get_fork_error(ad, return_value * 100, philosopher_number, philosopher_pre_number));
	}
	else if(ad->number % 2 == 0)
	{
	    pthread_mutex_lock(&(ad->mutex[*philosopher_pre_number]));
	    if((return_value = time_distinction_start_between_end(ad, "has taken a fork", *philosopher_number)) != 0)
			return (unlock_get_fork_error(ad, return_value * 1000, philosopher_number, philosopher_pre_number));
	    pthread_mutex_lock(&(ad->mutex[*philosopher_number]));
		if((return_value = time_distinction_start_between_end(ad, "has taken a fork", *philosopher_number)) != 0)
			return (unlock_get_fork_error(ad, return_value * 10000, philosopher_number, philosopher_pre_number));
	}
	return (0);
}

int *fork_unlock(t_all_data *ad, int philosopher_number, int philosopher_pre_number)
{
	pthread_mutex_unlock(&(ad->mutex[philosopher_number]));
	pthread_mutex_unlock(&(ad->mutex[philosopher_pre_number]));
	return(ad->return_value);
}

int eating(t_all_data *ad, int philosopher_number, int philosopher_pre_number)
{
	int return_value;

	return_value = 0;
	pthread_mutex_lock(ad->monitor_mutex);
    if((return_value = get_time(&(ad->t.last_eat_time[philosopher_number]))) != 0)
	{
		pthread_mutex_unlock(ad->monitor_mutex);
		return (return_value);
	}
	pthread_mutex_unlock(ad->monitor_mutex);
	if((return_value = get_time(&(ad->save_time))) != 0)
		return (return_value);
	return_value = time_distinction_start_between_end(ad, "is eating", philosopher_number);
    if (return_value != 0 || (return_value = (accurate_usleep(1000 * ad->pd.time_to_eat, ad->save_time))) != 0)
		return (return_value);
	return (0);
}

int sleeping(t_all_data *ad, int philosopher_number, int philosopher_pre_number)
{
	int return_value;

	return_value = 0;
	if((return_value = get_time(&(ad->save_time))) != 0)
	{
	    pthread_mutex_unlock(&(ad->mutex[philosopher_number]));
	    pthread_mutex_unlock(&(ad->mutex[philosopher_pre_number]));
		return (return_value);
	}
	return_value = time_distinction_start_between_end(ad, "is sleeping", philosopher_number);
    pthread_mutex_unlock(&(ad->mutex[philosopher_number]));
    pthread_mutex_unlock(&(ad->mutex[philosopher_pre_number]));
    if (return_value != 0 || (return_value = (accurate_usleep((1000 * ad->pd.time_to_sleep), ad->save_time))) != 0 )
		return (return_value);
	return (0);
}

void *t_philo_thread(void * arg)
{
    int philosopher_number;
    int philosopher_next_number;
    int philosopher_pre_number;
    t_all_data *ad = (t_all_data *)arg;

	set_around_number(ad, &philosopher_number, &philosopher_next_number, &philosopher_pre_number);
	philosophers_order(ad);
	*(ad->return_value) = 0;
    while(1)
    {
		if ((*(ad->return_value) = get_fork(ad, &philosopher_number, &philosopher_next_number, &philosopher_pre_number)) != 0)
			return (void *)(ad->return_value);
		if ((*(ad->return_value) = eating(ad, philosopher_number, philosopher_pre_number)) != 0)
			return (void *)(fork_unlock(ad, philosopher_number, philosopher_pre_number));
		if ((*(ad->return_value) = sleeping(ad, philosopher_number, philosopher_pre_number)) != 0)
			return (void *)(ad->return_value);
		if (((*ad->return_value) = time_distinction_start_between_end(ad, "is thinking", philosopher_number)) != 0)
			return (void *)(ad->return_value);
		if( ad->pd.time_to_eat > ad->pd.time_to_sleep)
			if ((*ad->return_value = (accurate_usleep((1000 * (ad->pd.time_to_eat - ad->pd.time_to_sleep)), 0))) == -2)
				return (void *)(ad->return_value);
		usleep(1000);
    }
    return (ad->return_value);
}
//		if(ad->pd.number_of_philosophers % 2 == 1)
//		{
//			if ((*ad->return_value = (accurate_usleep(1000 * ad->pd.time_to_eat, 0))) == -2)
//				return (void *)(ad->return_value);
//		}
