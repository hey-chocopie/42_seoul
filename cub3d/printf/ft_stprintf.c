/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 01:58:55 by hoylee            #+#    #+#             */
/*   Updated: 2020/09/06 20:59:38 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_count1_minus0_printf(struct s_person *width,
								long long int *save, char *st)
{
	while ((*save) > 0)
	{
		if (((*width).value_minus)-- == 1 && st[0] != 0)
		{
			((*width).result)++;
			write(1, "-", 1);
		}
		write(1, "0", 1);
		((*width).result)++;
		(*save)--;
	}
}

void			ft_count0_printf(struct s_person *width,
		char *st, long long int *save, long long int *save2)
{
	if (((*width).value_minus) == 1 && st[0] != 0)
		(*save)--;
	while ((*save) > 0 && (*width).minus != 1)
	{
		(*save)--;
		write(1, " ", 1);
		((*width).result)++;
	}
	if ((*width).jump == 1)
	{
		((*width).result)++;
		write(1, " ", 1);
	}
	while ((*save2)-- > 0)
	{
		if (((*width).value_minus)-- == 1 && st[0] != 0)
		{
			((*width).result)++;
			write(1, "-", 1);
		}
		write(1, "0", 1);
		((*width).result)++;
	}
}

void			ft_st_print(struct s_person *width, char *st, long long int *x)
{
	if (((*width).value_minus)-- == 1 && st[0] != 0)
	{
		((*width).result)++;
		write(1, "-", 1);
	}
	((*width).result)++;
	write(1, &st[(*x)], 1);
	(*x)++;
}

void			ft_st_print_minus(struct s_person *width,
					char *st, long long int *save, long long int *x)
{
	(*x) = 0;
	while (st[(*x)])
		ft_st_print(width, st, x);
	if ((*width).count == 0 && (*width).minus != 0)
	{
		while ((*save)-- > 0)
		{
			((*width).result)++;
			write(1, " ", 1);
		}
	}
	else if ((*width).count == 1 && (*width).minus != 0)
	{
		while ((*save)-- > 0)
		{
			((*width).result)++;
			write(1, " ", 1);
		}
	}
}

void			ft_stprintf(char *st, struct s_person *width)
{
	long long int		x;
	long long int		save;
	long long int		save2;

	if ((*width).save_count == 1 && (*width).tmp2_minus)
		(*width).count = 1;
	if ((st[0] == '0' && st[1] == 0) && (*width).period == 1)
		st[0] = 0;
	save2 = ft_save_set(st, width, &x, &save);
	if ((*width).value_minus == 1)
		save--;
	if ((*width).count == 1 && (*width).minus != 1)
		ft_count1_minus0_printf(width, &save, st);
	else if ((*width).count == 0)
	{
		if (x > (*width).tmp2)
			save = (*width).tmp - x;
		else if (x <= (*width).tmp2)
			save = (*width).tmp - (*width).tmp2;
		ft_count0_printf(width, st, &save, &save2);
	}
	ft_st_print_minus(width, st, &save, &x);
	free(st);
}
