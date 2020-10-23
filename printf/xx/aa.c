/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 03:24:12 by hoylee            #+#    #+#             */
/*   Updated: 2020/08/30 17:55:12 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_set(struct person *width)
{
	(*width).tmp = 0;
	(*width).tmp2 = 0;
	(*width).count = 0;
	(*width).decimal = 0;
	(*width).minus = 0;
	(*width).value_minus = 0;
	(*width).period = 0;
	(*width).star = 0;
	(*width).star2 = 0;
	(*width).c_null = 0;
	(*width).jump = 0;
	(*width).tmp2_minus = 0;
}

void	ft_check_persent(const char *args,
			int *i, struct person *width, va_list ap)
{
	if (args[(*i)] == '%')
	{
		if (ft_persent_count(args, i, width) && args[(*i) + 1] == '%')
		{
			((*width).result)++;
			write(1, "%", 1);
			(*i)++;
		}
		else
			ft_discrimination(args, i, ap, width);
	}
	else
	{
		write(1, &args[(*i)], 1);
		((*width).result)++;
	}
}

int		ft_printf(const char *args, ...)
{
	va_list				ap;
	struct person		width;
	int					i;

	width.result = 0;
	i = 0;
	va_start(ap, args);
	while (args[i])
	{
		ft_width_set(&width);
		ft_check_persent(args, &i, &width, ap);
		i++;
	}
	va_end(ap);
	return (width.result);
}

//#include <stdio.h>
//
//int main(void)
//{
//	char c;
//
//	c = 'y';
//	ft_printf("-->|%-4.c|<--\n", c);
//	printf("-->|%-4.c|<--\n", c);
//	ft_printf("-->|%-2.c|<--\n", c); 
//
//	printf("-->|%-2.c|<--\n", c); 
//}
