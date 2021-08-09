/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <hoylee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:04:24 by hoylee            #+#    #+#             */
/*   Updated: 2021/08/04 23:04:27 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	argv_check(int argc, char **argv)
{
	int	 i;
	int	 j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	argc_argv_check(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (-1);
	if (argv_check(argc, argv) == 0)
		return (-1);
	return (0);
}

int	set_argv_data(int argc, char **argv, t_all_data *ad)
{
	int	 i;
	int	 tmp;

	i = 1;
	ad->pd.number_of_times_each_philosopher_must_eat = -1;
	while (i < argc)
	{
		tmp = ft_atoi(argv[i]);
		if (tmp <= 0 || (tmp < 60 && (i == 3 || i == 4)))
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
