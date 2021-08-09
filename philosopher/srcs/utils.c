/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <hoylee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:06:32 by hoylee            #+#    #+#             */
/*   Updated: 2021/08/04 23:06:33 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	error_print(int error_code)
{
	if (error_code == -1)
		printf("arguments error!\n");
	else if (error_code == -2)
		printf("gettimeofday error!\n");
	else if (error_code == -3)
		printf("malloc error!\n");
	else if (error_code == -4)
		printf("pthread_mutex_init error!\n");
	else if (error_code == -5)
		printf("thread create error\n");
}

void	tmp_free(t_all_data *ad, t_all_data **tmp)
{
	int			i;

	i = -1;
	while (++i < ad->pd.number_of_philosophers)
		if ((*tmp) != 0 && (*tmp)[i].return_value != 0)
			free((*tmp)[i].return_value);
	i = -1;
	while (++i < ad->pd.number_of_philosophers)
		if ((*tmp) != 0 && (*tmp)[i].monitor_return_value != 0)
			free((*tmp)[i].monitor_return_value);
	if (*tmp != 0)
		free(*tmp);
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
	if (ad->eat_count != 0)
		free(ad->eat_count);
	tmp_free(ad, tmp);
}

void	malloc_reset(t_all_data *ad, t_all_data **tmp)
{
	ad->mutex = 0;
	ad->monitor_mutex = 0;
	ad->print_mutex = 0;
	ad->philosopher = 0;
	ad->monitor = 0;
	ad->t.last_eat_time = 0;
	ad->die_flag = 0;
	ad->die_index = 0;
	ad->monitor_return_value = 0;
	ad->eat_count = 0;
	*tmp = 0;
}

int	get_time(unsigned long long *save)
{
	struct timeval	now;

	if (gettimeofday(&now, 0) == -1)
		return (-2);
	*save = (now.tv_sec * 1000000) + (now.tv_usec);
	return (0);
}
