/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimalnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 14:12:40 by hoylee            #+#    #+#             */
/*   Updated: 2020/08/30 15:18:14 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

int		exceptbase(char **base)
{
	int				count;
	int				count2;

	count = 0;
	count2 = 0;
	if ((*base)[0] == '\0' || (*base)[1] == '\0')
		return (1);
	while ((*base)[count])
	{
		count2 = count + 1;
		while ((*base)[count2])
		{
			if ((*base)[count] == (*base)[count2])
				return (1);
			count2++;
		}
		if ((*base)[count] == '+' || (*base)[count] == '-')
			return (1);
		count++;
	}
	return (0);
}

void	adress(unsigned int a, char *base, int *countnum, char *result)
{
	a = a / 16;
	if (a >= 16)
	{
		adress(a, base, countnum, result);
	}
	a = a % 16;
	result[(*countnum)] = base[a];
	(*countnum)++;
}

void	maloccount(unsigned long long int nbr, int *countnum)
{
	nbr = nbr / 16;
	(*countnum)++;
	if (nbr >= 16)
		maloccount(nbr, countnum);
}

void	ft_sixteen_recursion(unsigned int *nbr, char *base,
								int *countnum, char *result)
{
	if ((*nbr) >= 16)
	{
		adress(*nbr, base, countnum, result);
		result[(*countnum)] = base[(*nbr) % 16];
		(*countnum)++;
	}
	else if ((*nbr) >= 1)
	{
		result[(*countnum)] = base[(*nbr) % 16];
		(*countnum)++;
	}
}

char	*ft_putnbr_base(unsigned int nbr, char *base)
{
	char			*result;
	int				countnum;

	countnum = 0;
	if (0 == exceptbase(&base))
	{
		maloccount(nbr, &countnum);
		result = (char *)malloc(sizeof(char) * ((countnum) + 1 + 1));
		(countnum) = 0;
		if (nbr >= 1)
			ft_sixteen_recursion(&nbr, base, &countnum, result);
		else if (nbr == 0)
			adress(nbr, base, &countnum, result);
		result[countnum] = 0;
	}
	else
	{
		result = (char *)malloc(sizeof(char) * 1);
		result[0] = 0;
	}
	return (result);
}
