/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stprintf2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 02:18:08 by hoylee            #+#    #+#             */
/*   Updated: 2020/08/30 03:13:42 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int	ft_save_set(char *st, struct person *width,
						long long int *x, long long int *save)
{
	(*x) = 0;
	while (st[*x])
		(*x)++;
	(*save) = (*width).tmp - (*x);
	return ((*width).tmp2 - (*x));
}
