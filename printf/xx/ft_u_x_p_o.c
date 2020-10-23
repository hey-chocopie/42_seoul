/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_x_p_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 02:49:21 by hoylee            #+#    #+#             */
/*   Updated: 2020/08/30 03:15:00 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_u(va_list ap, struct person *width)
{
	unsigned int			save;

	save = va_arg(ap, unsigned int);
	ft_stprintf(ft_itoa_u((unsigned long long int)save), width);
}

void	ft_x(va_list ap, struct person *width)
{
	unsigned int			save;

	save = va_arg(ap, unsigned int);
	ft_stprintf(ft_putnbr_base(save, "0123456789abcdef"), width);
}

void	ft_xx(va_list ap, struct person *width)
{
	int						save;

	save = va_arg(ap, int);
	ft_stprintf(ft_putnbr_base(save, "0123456789ABCDEF"), width);
}

void	ft_p(va_list ap, struct person *width)
{
	unsigned long long int	save;
	char					*result;

	save = va_arg(ap, unsigned long long int);
	if (save == 0)
	{
		result = (char *)malloc(sizeof(char) * 4);
		result[0] = '0';
		result[1] = 'x';
		result[2] = '0';
		result[3] = 0;
		ft_stprintf(result, width);
	}
	else
		ft_stprintf(ft_putnbr_base2(save, "0123456789abcdef"), width);
}

void	ft_o(va_list ap, struct person *width)
{
	unsigned int			save;

	save = va_arg(ap, unsigned int);
	ft_stprintf(ft_putnbr_base8(save, "01234567"), width);
}
