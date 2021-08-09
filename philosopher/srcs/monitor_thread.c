/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <hoylee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:04:55 by hoylee            #+#    #+#             */
/*   Updated: 2021/08/04 23:04:56 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*die_to_philosopher(t_all_data *ad)
{
	*(ad->die_index) = ad->number;
	*(ad->die_flag) = 1;
	pthread_mutex_unlock(ad->monitor_mutex);
	*ad->monitor_return_value = print_t_data(ad,
			"died", ad->number);
	return ((void *)(ad->monitor_return_value));
}

int	check_finish_eat(t_all_data *ad)
{
	int	i;

	i = 0;
	if (ad->pd.number_of_times_each_philosopher_must_eat == -1)
		return (0);
	while (i < ad->pd.number_of_philosophers)
	{
		if (ad->eat_count[i] < ad->pd.number_of_times_each_philosopher_must_eat)
			break ;
		i++;
	}
	if (i == ad->pd.number_of_philosophers)
		return (1);
	return (0);
}

void	*complet_eat(t_all_data *ad)
{
	*(ad->die_flag) = 1;
	pthread_mutex_unlock(ad->monitor_mutex);
	*ad->monitor_return_value = print_t_data(ad,
			"philosopher eat finish.", -1);
	return ((void *)(ad->monitor_return_value));
}

void	*monitor_thread(void *arg)
{
	t_all_data	*ad;

	ad = (t_all_data *)arg;
	*(ad->monitor_return_value) = 0;
	while (1)
	{
		pthread_mutex_lock(ad->monitor_mutex);
		if (*(ad->die_flag) == 1 || *(ad->die_flag) == 2)
		{
			pthread_mutex_unlock(ad->monitor_mutex);
			return ((void *)(ad->monitor_return_value));
		}
		*ad->monitor_return_value = get_time(&ad->t.now_msecs_time);
		if (*ad->monitor_return_value == -2)
			return ((void *)(ad->monitor_return_value));
		if (((ad->t.now_msecs_time - ad->t.last_eat_time[ad->number])
				/ 1000) > (unsigned long long)ad->pd.time_to_die)
			return (die_to_philosopher(ad));
		else if (check_finish_eat(ad) == 1)
			return (complet_eat(ad));
		else
			pthread_mutex_unlock(ad->monitor_mutex);
		usleep(100);
	}
	return ((void *)(ad->monitor_return_value));
}
