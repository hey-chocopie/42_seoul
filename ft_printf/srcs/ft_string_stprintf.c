/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_stprintf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 02:27:18 by hoylee            #+#    #+#             */
/*   Updated: 2020/09/02 19:20:11 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_string_count1_minus0(struct s_person *width,
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

void		ft_string_count0(struct s_person *width,
			long long int *save, char *st, long long int *x)
{
	if ((*width).period == 1 && ((*width).tmp2 == 0 && (*width).tmp != 0))
		(*save) = (*width).tmp;
	else if ((*width).tmp2 == 0)
		(*save) = (*width).tmp - (*x);
	else if ((*x) > (*width).tmp2)
		(*save) = (*width).tmp - (*width).tmp2;
	else if ((*x) <= (*width).tmp2)
		(*save) = (*width).tmp - (*x);
	if (((*width).value_minus) == 1 && st[0] != 0)
		(*save)--;
	while ((*save) > 0 && (*width).minus != 1)
	{
		((*width).result)++;
		(*save)--;
		write(1, " ", 1);
	}
}

void		ft_string_stprint(char *st,
				struct s_person *width, long long int *x)
{
	while (st[(*x)] && ((*width).tmp2 > (*x) || (*width).tmp2 == 0))
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
}

void		ft_string_width_back(struct s_person *width,
									long long int *save)
{
	if ((*width).c_null == 1)
	{
		((*width).result)++;
		write(1, "\0", 1);
	}
	if ((*width).count == 0 && (*width).minus != 0)
		while ((*save)-- > 0)
		{
			((*width).result)++;
			write(1, " ", 1);
		}
}

void		ft_string_stprintf(char *st, struct s_person *width)
{
	long long int x;
	long long int save;
	long long int save2;

	if ((*width).c_null == 1 && (*width).tmp != 0)
		(*width).tmp--;
	save2 = ft_save_set(st, width, &x, &save);
	if ((*width).value_minus == 1)
		save--;
	if ((*width).count == 1 && (*width).minus != 1)
		ft_string_count1_minus0(width, &save, st);
	else if ((*width).count == 0)
		ft_string_count0(width, &save, st, &x);
	x = 0;
	if ((*width).period == 1 && (*width).tmp2 == 0)
	{
		if ((*width).tmp != 0 && (*width).tmp2 == 0)
			save = (*width).tmp;
	}
	else
		ft_string_stprint(st, width, &x);
	ft_string_width_back(width, &save);
	free(st);
}
