/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 01:49:09 by hoylee            #+#    #+#             */
/*   Updated: 2020/08/30 03:10:36 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_int_min(char *max, struct person *width)
{
	(*width).value_minus = 1;
	max[0] = '2';
	max[1] = '1';
	max[2] = '4';
	max[3] = '7';
	max[4] = '4';
	max[5] = '8';
	max[6] = '3';
	max[7] = '6';
	max[8] = '4';
	max[9] = '8';
	max[10] = '\0';
}

void	ft_d_input_zero(char **a)
{
	(*a) = (char*)malloc(sizeof(char) * 2);
	(*a)[0] = '0';
	(*a)[1] = 0;
}

void	ft_d(va_list ap, struct person *width)
{
	int		save;
	char	*a;
	char	*max;

	save = va_arg(ap, int);
	if (save < 0 && save != -2147483648)
	{
		save = (save * (-1));
		(*width).value_minus = 1;
	}
	if (save == -2147483648)
	{
		max = (char *)malloc(sizeof(char) * 11);
		ft_int_min(max, width);
		ft_stprintf(max, width);
	}
	else if (save == 0)
	{
		ft_d_input_zero(&a);
		ft_stprintf(a, width);
	}
	else
		ft_stprintf(ft_itoa(save), width);
}
