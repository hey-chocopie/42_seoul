/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_discrimination.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 01:36:46 by hoylee            #+#    #+#             */
/*   Updated: 2020/08/30 17:07:49 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_num(const char *args, int *i,
					struct person *width, int *j)
{
	(*j) = 1;
	if (args[(*i) + (*j)] == '-' || args[(*i) + (*j)] == '0')
		ft_firstzero_count(args, i, j, width);
	else if (args[(*i) + (*j)] == '.')
		ft_nonnum_count(args, i, j, width);
	else if (args[(*i) + (*j)] > '0' && args[(*i) + (*j)] <= '9')
		ft_firstnonzero_count(args, i, j, width);
	else if (args[(*i) + (*j)] == ' ')
		ft_jump(args, i, j, width);
	if (args[(*i) + (*j)] == '*')
		ft_nonnum_count(args, i, j, width);
}

void	ft_star_num(struct person *width, va_list ap)
{
	if ((*width).star == 1)
	{
		(*width).tmp = va_arg(ap, int);
		if ((*width).tmp < 0)
		{
			(*width).tmp = (*width).tmp * (-1);
			(*width).minus = 1;
		}
	}
	if ((*width).star2 == 1)
	{
		(*width).tmp2 = va_arg(ap, int);
		if ((*width).tmp2 < 0)
		{
			(*width).tmp2 = (*width).tmp2 * (-1);
			(*width).tmp2_minus = 1;
			(*width).tmp2 = 0;
			(*width).period = 0;
		}
	}
}

void	ft_discrimination(const char *args, int *i,
					va_list ap, struct person *width)
{
	int		j;

	ft_width_num(args, i, width, &j);
	ft_star_num(width, ap);
	if (args[(*i) + (j)] == 'd')
		ft_d(ap, width);
	else if (args[(*i) + (j)] == 'i')
		ft_d(ap, width);
	else if (args[(*i) + (j)] == 'u')
		ft_u(ap, width);
	else if (args[(*i) + (j)] == 'x')
		ft_x(ap, width);
	else if (args[(*i) + (j)] == 'X')
		ft_xx(ap, width);
	else if (args[(*i) + (j)] == 's')
		ft_s(ap, width);
	else if (args[(*i) + (j)] == 'c')
		ft_c(ap, width);
	else if (args[(*i) + (j)] == 'p')
		ft_p(ap, width);
	else if (args[(*i) + (j)] == 'o')
		ft_o(ap, width);
	*i = (*i) + j;
}
