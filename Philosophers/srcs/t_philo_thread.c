#include "../include/philo.h"

int	get_fork(t_all_data *ad, int *ph_number, int *ph_pre_numbe)
{
	int		return_v;

	if (ad->number % 2 == 1)
	{
		pthread_mutex_lock(&(ad->mutex[*ph_number]));
		return_v = print_t_data(ad, "has taken a fork", *ph_number);
		if (return_v != 0)
			return (unlock_fork(ad, return_v * 10, ph_number, ph_pre_numbe));
		pthread_mutex_lock(&(ad->mutex[*ph_pre_numbe]));
		return_v = print_t_data(ad, "has taken a fork", *ph_number);
		if (return_v != 0)
			return (unlock_fork(ad, return_v * 100, ph_number, ph_pre_numbe));
	}
	else if (ad->number % 2 == 0)
	{
		pthread_mutex_lock(&(ad->mutex[*ph_pre_numbe]));
		return_v = print_t_data(ad, "has taken a fork", *ph_number);
		if (return_v != 0)
			return (unlock_fork(ad, return_v * 1000, ph_number, ph_pre_numbe));
		pthread_mutex_lock(&(ad->mutex[*ph_number]));
		return_v = print_t_data(ad, "has taken a fork", *ph_number);
		if (return_v != 0)
			return (unlock_fork(ad, return_v * 10000, ph_number, ph_pre_numbe));
	}
	return (0);
}

int	eating(t_all_data *ad, int ph_number)
{
	int		return_value;

	return_value = 0;
	pthread_mutex_lock(ad->monitor_mutex);
	return_value = get_time(&(ad->t.last_eat_time[ph_number]));
	if (return_value != 0)
	{
		pthread_mutex_unlock(ad->monitor_mutex);
		return (return_value);
	}
	pthread_mutex_unlock(ad->monitor_mutex);
	return_value = get_time(&(ad->save_time));
	if (return_value != 0)
		return (return_value);
	return_value = print_t_data(ad, "is eating", ph_number);
	if (return_value != 0)
		return (return_value);
	return_value = (accurate_usleep(1000 * ad->pd.time_to_eat, ad->save_time));
	if (return_value != 0)
		return (return_value);
	pthread_mutex_lock(ad->monitor_mutex);
	(ad->eat_count[ph_number])++;
	pthread_mutex_unlock(ad->monitor_mutex);
	return (0);
}

int	sleeping(t_all_data *ad, int ph_number, int ph_pre_number)
{
	int		return_value;

	return_value = 0;
	return_value = get_time(&(ad->save_time));
	if (return_value != 0)
	{
		pthread_mutex_unlock(&(ad->mutex[ph_number]));
		pthread_mutex_unlock(&(ad->mutex[ph_pre_number]));
		return (return_value);
	}
	return_value = print_t_data(ad, "is sleeping", ph_number);
	pthread_mutex_unlock(&(ad->mutex[ph_number]));
	pthread_mutex_unlock(&(ad->mutex[ph_pre_number]));
	if (return_value != 0)
		return (return_value);
	return_value = accurate_usleep(1000 * ad->pd.time_to_sleep, ad->save_time);
	if (return_value != 0)
		return (return_value);
	return (0);
}

void	*philosopher_Routine(t_all_data *ad, int ph_number,
	int ph_pre_number)
{
	*(ad->return_value) = get_fork(ad,
			&ph_number, &ph_pre_number);
	if (*(ad->return_value) != 0)
		return ((void *)(ad->return_value));
	*(ad->return_value) = eating(ad, ph_number);
	if (*(ad->return_value) != 0)
		return ((void *)(fork_unlock(ad, ph_number, ph_pre_number)));
	*(ad->return_value) = sleeping(ad, ph_number, ph_pre_number);
	if (*(ad->return_value) != 0)
		return ((void *)(ad->return_value));
	*ad->return_value = print_t_data(ad, "is thinking", ph_number);
	if (*ad->return_value != 0)
		return ((void *)(ad->return_value));
	if (ad->pd.time_to_eat > ad->pd.time_to_sleep)
	{
		*ad->return_value = accurate_usleep((1000
					* (ad->pd.time_to_eat - ad->pd.time_to_sleep)), 0);
		if (*ad->return_value == -2)
			return ((void *)(ad->return_value));
	}
	return ((void *)(ad->return_value));
}

void	*t_philo_thread(void *arg)
{
	int			ph_number;
	int			ph_next_number;
	int			ph_pre_number;
	t_all_data	*ad;

	ad = (t_all_data *)arg;
	set_around_number(ad, &ph_number, &ph_next_number, &ph_pre_number);
	philosophers_order(ad);
	*(ad->return_value) = 0;
	if (ad->pd.number_of_philosophers == 1)
		usleep(ad->pd.time_to_die * 1000 + 5000);
	while (1)
	{
		if (*((int *)philosopher_Routine(ad, ph_number,
					ph_pre_number)) != 0)
			return ((void *)(ad->return_value));
		usleep(1000);
	}
	return (ad->return_value);
}
