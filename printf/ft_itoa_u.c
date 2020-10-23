/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:03:56 by hoylee            #+#    #+#             */
/*   Updated: 2020/09/06 21:28:15 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_sizeitoa2(long long int n, long long int max)
{
	int						count;

	count = 0;
	if (n < 0)
	{
		n = n * -1;
		count++;
	}
	while (max >= 1)
	{
		count++;
		n = n % max;
		max = max / 10;
	}
	return (count);
}

void	ft_setitoa2(int *count, unsigned long long int *nn,
						int *max, unsigned long long int *n)
{
	(*nn) = (*n);
	(*count) = 0;
	(*max) = 1000000000;
}

int		ft_itoa_n_null(char **a, unsigned long long int n)
{
	if (n == 0)
	{
		(*a) = (char *)malloc(sizeof(char) * 2);
		(*a)[0] = '0';
		(*a)[1] = 0;
		return (1);
	}
	return (0);
}

char	*ft_itoa_u(unsigned long long int n)
{
	int						max;
	char					*a;
	int						count;
	unsigned long long int	nn;

	if (ft_itoa_n_null(&a, n) == 1)
		return (a);
	ft_setitoa2(&count, &nn, &max, &n);
	count = ft_sizeitoa2(n, max);
	if (!(a = (char *)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	count = 0;
	while (nn / max == 0 && max > 1)
	{
		max = max / 10;
	}
	while (max >= 1)
	{
		a[count++] = (nn / max) + '0';
		nn = nn % max;
		max = max / 10;
	}
	a[count] = 0;
	return (a);
}
