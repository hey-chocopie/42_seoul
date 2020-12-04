/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 14:58:29 by hoylee            #+#    #+#             */
/*   Updated: 2020/07/12 15:06:37 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sizeitoa(int n, int max)
{
	int count;

	count = 0;
	if (n < 0)
	{
		n = n * -1;
		count++;
	}
	while (n / max == 0 && max > 1)
		max = max / 10;
	while (max >= 1)
	{
		count++;
		n = n % max;
		max = max / 10;
	}
	return (count);
}

void	ft_setitoa(int *count, long long int *nn, int *max, int *n)
{
	(*nn) = (long long int)(*n);
	(*count) = 0;
	(*max) = 1000000000;
}

char	*ft_itoa(int n)
{
	int				max;
	char			*a;
	int				count;
	long long int	nn;

	ft_setitoa(&count, &nn, &max, &n);
	count = ft_sizeitoa(n, max);
	if (!(a = (char *)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	count = 0;
	if (nn < 0)
	{
		a[count++] = '-';
		nn = nn * -1;
	}
	while (nn / max == 0 && max > 1)
		max = max / 10;
	while (max >= 1)
	{
		a[count++] = (nn / max) + '0';
		nn = nn % max;
		max = max / 10;
	}
	a[count] = 0;
	return (a);
}
