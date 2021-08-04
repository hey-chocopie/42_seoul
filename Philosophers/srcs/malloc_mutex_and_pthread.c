#include "../include/philo.h"

void	set_value_to_malloc(t_all_data *ad, t_all_data **tmp)
{
	int		i;

	i = -1;
	*(ad->die_flag) = 0;
	*(ad->die_index) = -1;
	while (++i < ad->pd.number_of_philosophers)
	{
		(*tmp)[i] = (*ad);
		(*tmp)[i].monitor_return_value = 0;
	}
}

int	malloc_tmp_data(t_all_data **tmp, int i)
{
	(*tmp)[i].number = i;
	(*tmp)[i].return_value = malloc(sizeof(int) * 1);
	if ((*tmp)[i].return_value == 0)
		return (-3);
	(*tmp)[i].monitor_return_value = malloc(sizeof(int) * 1);
	if ((*tmp)[i].monitor_return_value == 0)
		return (-3);
	return (0);
}

int	malloc_mutex(t_all_data *ad)
{
	int		i;

	i = 0;
	ad->mutex = malloc(ad->pd.number_of_philosophers * sizeof(pthread_mutex_t));
	if (0 == ad->mutex)
		return (-3);
	ad->monitor_mutex = malloc(sizeof(pthread_mutex_t));
	if (0 == ad->monitor_mutex)
		return (-3);
	ad->print_mutex = malloc(sizeof(pthread_mutex_t));
	if (0 == ad->print_mutex)
		return (-3);
	while (i < ad->pd.number_of_philosophers)
	{
		if (pthread_mutex_init(&ad->mutex[i], NULL) == -1)
			return (-4);
		i++;
	}
	if (pthread_mutex_init(ad->monitor_mutex, NULL) == -1)
		return (-4);
	if (pthread_mutex_init(ad->print_mutex, NULL) == -1)
		return (-4);
	return (0);
}

int	malloc_pthread(t_all_data *ad, t_all_data **tmp)
{
	ad->philosopher = malloc(ad->pd.number_of_philosophers * sizeof(pthread_t));
	if (0 == ad->philosopher)
		return (-3);
	ad->monitor = malloc(ad->pd.number_of_philosophers * sizeof(pthread_t));
	if (0 == ad->monitor)
		return (-3);
	ad->t.last_eat_time = malloc(ad->pd.number_of_philosophers
			* sizeof(unsigned long long));
	if (0 == ad->t.last_eat_time)
		return (-3);
	ad->die_flag = malloc(sizeof(int));
	if (0 == ad->die_flag)
		return (-3);
	ad->die_index = malloc(sizeof(int));
	if (0 == ad->die_index)
		return (-3);
	ad->eat_count = malloc(sizeof(int) * ad->pd.number_of_philosophers);
	if (0 == ad->eat_count)
		return (-3);
	*tmp = malloc(ad->pd.number_of_philosophers * sizeof(t_all_data));
	if (0 == *tmp)
		return (-3);
	set_value_to_malloc(ad, tmp);
	return (0);
}
