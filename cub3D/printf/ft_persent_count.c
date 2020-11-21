/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_persent_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 01:31:10 by hoylee            #+#    #+#             */
/*   Updated: 2020/09/06 21:25:15 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		per_num_count(const char *args, int *i, int *j, struct s_person *width)
{
	int		much;

	much = 0;
	while (args[(*i) + 1 + (*j)] >= '0' && args[(*i) + 1 + (*j)] <= '9')
	{
		much = ((much) * 10) + (args[(*i) + 1 + (*j)] - '0');
		(*j)++;
	}
	if (args[(*i) + 1 + (*j)] == '*')
	{
		(*j)++;
		(*width).persent_count = 1;
	}
	while ((args[(*i) + 1 + (*j)] >= 48 && args[(*i) + 1 + (*j)] <= 57)
										|| args[(*i) + 1 + (*j)] == '.')
		(*j)++;
	if (args[(*i) + 1 + (*j)] == '*')
	{
		(*j)++;
		(*width).persent_count2 = 1;
	}
	return (much);
}

int		set_per_count(int *zero, int *i, int *j, const char *args)
{
	int manus;

	manus = 0;
	(*zero) = 0;
	(*j) = 0;
	while (args[(*i) + 1 + (*j)] == '-' || args[(*i) + 1 + (*j)] == '0'
										|| args[(*i) + 1 + (*j)] == ' ')
	{
		if (args[(*i) + 1 + (*j)] == '0')
			(*zero) = 1;
		else if (args[(*i) + 1 + (*j)] == '-')
		{
			manus = 1;
			(*zero) = 0;
		}
		(*j)++;
	}
	return (manus);
}

void	ft_persent_width(int *manus, int *much,
					struct s_person *width, int *zero)
{
	if ((*manus) == 0)
	{
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
	}
	write(1, "%", 1);
	((*width).result)++;
	if ((*manus) == 1)
		while (--(*much))
		{
			((*width).result)++;
			write(1, " ", 1);
		}
}

void	ft_persent_much(int *manus, int *much,
					struct s_person *width, int *zero)
{
	if ((*much) != 0)
		ft_persent_width(manus, much, width, zero);
	else if ((*much) == 0)
	{
		((*width).result)++;
		write(1, "%", 1);
	}
}

int		ft_persent_count(const char *args, int *i,
					struct s_person *width, va_list ap)
{
	int		j;
	int		much;
	int		manus;
	int		zero;

	manus = 0;
	much = 0;
	if (args == 0 || i == 0 || width == 0 || ap == 0)
		return (0);
	manus = set_per_count(&zero, i, &j, args);
	much = per_num_count(args, i, &j, width);
	if (args[(*i) + 1 + j] == '%')
	{
		(*i) = (*i) + j;
		if ((*width).persent_count == 1)
			much = va_arg(ap, int);
		if ((*width).persent_count2 == 1)
			va_arg(ap, int);
		ft_persent_much(&manus, &much, width, &zero);
		return (1);
	}
	return (0);
}
