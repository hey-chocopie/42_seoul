/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 22:59:17 by hoylee            #+#    #+#             */
/*   Updated: 2020/09/02 17:42:50 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fullstop(const char *args,
						int *i, int *j, struct s_person *width)
{
	(*j)++;
	(*width).period = 1;
	(*width).save_count = (*width).count;
	(*width).count = 0;
	while (args[(*i) + (*j)] == '0')
	{
		((*width).decimal)++;
		(*j)++;
	}
	while ((args[(*i) + (*j)] >= '0' && args[(*i) + (*j)] <= '9'))
	{
		((*width).tmp2) = (((*width).tmp2) * 10) + (args[(*i) + (*j)] - '0');
		(*j)++;
	}
	if (args[(*i) + (*j)] == '*')
	{
		(*width).star2 = 1;
		(*j)++;
	}
}

void	ft_nonnum_count(const char *args,
					int *i, int *j, struct s_person *width)
{
	if ((args[(*i) + (*j)]) == '*')
	{
		(*width).star = 1;
		(*j)++;
	}
	if ((args[(*i) + (*j)]) == '.')
		ft_fullstop(args, i, j, width);
}

void	ft_firstnonzero_count(const char *args,
					int *i, int *j, struct s_person *width)
{
	while ((args[(*i) + (*j)] >= '0' && args[(*i) + (*j)] <= '9'))
	{
		(*width).tmp = ((*width).tmp * 10) + (args[(*i) + (*j)] - '0');
		(*j)++;
	}
	ft_nonnum_count(args, i, j, width);
}

void	ft_firstzero_count(const char *args,
					int *i, int *j, struct s_person *width)
{
	while (args[(*i) + (*j)] == '0' || args[(*i) + (*j)] == '-')
	{
		if (args[(*i) + (*j)] == '0')
		{
			(*width).count = 1;
			(*j)++;
		}
		if (args[(*i) + (*j)] == '-')
		{
			(*width).minus = 1;
			(*j)++;
		}
	}
	ft_firstnonzero_count(args, i, j, width);
}

void	ft_jump(const char *args, int *i, int *j, struct s_person *width)
{
	while ((args[(*i) + (*j)]) == ' ')
	{
		(*j)++;
		(*width).jump = 1;
	}
	if ((args[(*i) + (*j)]) == '*')
		ft_nonnum_count(args, i, j, width);
}
