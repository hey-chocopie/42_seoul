#include "../include/philo.h"

void	set_around_number(t_all_data *ad, int *ph_number,
	int *ph_next_number, int *ph_pre_number)
{
	*ph_number = ad->number;
	*ph_next_number = (ad->number + 1) % (ad->pd.number_of_philosophers);
	if ((*ph_number - 1) == -1)
		*ph_pre_number = (ad->pd.number_of_philosophers - 1);
	else
		*ph_pre_number = *ph_number - 1;
}

void	philosophers_order(t_all_data *ad)
{
	if (ad->number % 2 == 1)
		accurate_usleep(1000 * ad->pd.time_to_eat, 0);
	if (ad->pd.number_of_philosophers % 2 == 1)
		if (ad->pd.number_of_philosophers == ad->number + 1)
			accurate_usleep(1000 * ad->pd.time_to_eat * 2, 0);
}

int	*fork_unlock(t_all_data *ad, int ph_number, int ph_pre_number)
{
	pthread_mutex_unlock(&(ad->mutex[ph_number]));
	pthread_mutex_unlock(&(ad->mutex[ph_pre_number]));
	return (ad->return_value);
}

int	unlock_fork(t_all_data *ad, int return_value,
	int *ph_number, int *ph_pre_number)
{
	if (return_value / 10000 != 0)
	{
		pthread_mutex_unlock(&(ad->mutex[*ph_pre_number]));
		pthread_mutex_unlock(&(ad->mutex[*ph_number]));
		return (return_value / 10000);
	}
	else if (return_value / 1000 != 0)
	{
		pthread_mutex_unlock(&(ad->mutex[*ph_pre_number]));
		return (return_value / 1000);
	}
	else if (return_value / 100 != 0)
	{
		pthread_mutex_unlock(&(ad->mutex[*ph_number]));
		pthread_mutex_unlock(&(ad->mutex[*ph_pre_number]));
		return (return_value / 100);
	}
	if (return_value / 10 != 0)
	{
		pthread_mutex_unlock(&(ad->mutex[*ph_number]));
		return (return_value / 10);
	}
	return (0);
}
