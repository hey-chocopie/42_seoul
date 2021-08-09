/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <hoylee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:05:42 by hoylee            #+#    #+#             */
/*   Updated: 2021/08/04 23:05:43 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	make_philosophers_thread_and_monitor_thread(t_all_data *ad,
										 t_all_data **tmp)
{
	int			i;
	int			thr_id;
	int			m_thr_id;

	i = 0;
	while (i < ad->pd.number_of_philosophers)
	{
		if (malloc_tmp_data(tmp, i) == -3)
			return (-3);
		thr_id = pthread_create(&ad->philosopher[i],
				NULL, t_philo_thread, (&((*tmp)[i])));
		m_thr_id = pthread_create(&ad->monitor[i], NULL,
				monitor_thread, (&((*tmp)[i])));
		if (thr_id < 0 || m_thr_id < 0)
			return (-5);
		i++;
	}
	return (0);
}

int	create_thread(t_all_data *ad, t_all_data **tmp)
{
	int			i;

	i = malloc_pthread(ad, tmp);
	if (i < 0)
		return (i);
	i = -1;
	while (++i < ad->pd.number_of_philosophers)
	{
		ad->eat_count[i] = 0;
		if (get_time(&(ad->t.last_eat_time[i])) == -2)
			return (-2);
	}
	i = make_philosophers_thread_and_monitor_thread(ad, tmp);
	if (i < 0)
		return (i);
	return (0);
}

int	excute_function(int argc, char **argv,
					t_all_data *ad, t_all_data **tmp)
{
	int	error_code;

	error_code = 0;
	error_code = argc_argv_check(argc, argv);
	if (error_code < 0)
		return (error_code);
	error_code = set_argv_data(argc, argv, ad);
	if (error_code < 0)
		return (error_code);
	error_code = get_time(&(*ad).t.start_msecs_time);
	if (error_code < 0)
		return (error_code);
	error_code = malloc_mutex(ad);
	if (error_code < 0)
		return (error_code);
	error_code = create_thread(ad, tmp);
	if (error_code < 0)
		return (error_code);
	return (0);
}

void	thread_wait(t_all_data *ad)
{
	int			i;
	int			error_code;
	void		*status;

	i = -1;
	error_code = 0;
	while (++i < ad->pd.number_of_philosophers)
	{
		pthread_join(ad->philosopher[i], (void **)&status);
		error_code = *((int *)status);
		if (error_code < 0)
			error_print(error_code);
		pthread_join(ad->monitor[i], (void **)&status);
		error_code = *((int *)status);
		if (error_code < 0)
			error_print(error_code);
	}
}

int	main(int argc, char **argv)
{
	int			error_code;
	t_all_data	*tmp;
	t_all_data	ad;

	malloc_reset(&ad, &tmp);
	error_code = excute_function(argc, argv, &ad, &tmp);
	if (error_code < 0)
	{
		error_print(error_code);
		all_free(&ad, &tmp);
		return (-1);
	}
	thread_wait(&ad);
	all_free(&ad, &tmp);
	return (0);
}
