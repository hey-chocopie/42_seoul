/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_persent_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 01:31:10 by hoylee            #+#    #+#             */
/*   Updated: 2020/08/30 03:12:16 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	per_num_count(const char *args, int *i, int *j, int *much)
{
	while (args[(*i) + 1 + (*j)] >= '0' && args[(*i) + 1 + (*j)] <= '9')
	{
		(*much) = ((*much) * 10) + (args[(*i) + 1 + (*j)] - '0');
		(*j)++;
	}
}

void	set_per_count(int *zero, int *much, int *j, int *manus)
{
	(*zero) = 0;
	(*much) = 0;
	(*j) = 0;
	(*manus) = 0;
}

void	ft_persent_width(int *manus, int *much, struct person *width, int *zero)
{
	if ((*manus) == 0)
		while (--(*much))
		{
			if ((*zero) == 1)
			{
				((*width).result)++;
				write(1, "0", 1);
			}
			else if ((*zero) == 0)
			{
				((*width).result)++;
				write(1, " ", 1);
			}
		}
	write(1, "%", 1);
	((*width).result)++;
	if ((*manus) == 1)
		while (--(*much))
			write(1, " ", 1);
}

int		ft_persent_count(const char *args, int *i, struct person *width)
{
	int		j;
	int		much;
	int		manus;
	int		zero;

	set_per_count(&zero, &much, &j, &manus);
	while (args[(*i) + 1 + j] == '-' || args[(*i) + 1 + j] == '0')
	{
		if (args[(*i) + 1 + j] == '-')
			manus = 1;
		else if (args[(*i) + 1 + j] == '0')
			zero = 1;
		j++;
	}
	per_num_count(args, i, &j, &much);
	if (much != 0 && args[(*i) + 1 + j] == '%')
	{
		(*i) = (*i) + j;
		ft_persent_width(&manus, &much, width, &zero);
		return (0);
	}
	return (1);
}
