/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimalnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 14:12:40 by hoylee            #+#    #+#             */
/*   Updated: 2020/09/02 01:31:41 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		exceptbase8(char **base)
{
	int							count;
	int							count2;

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

void	adress8(unsigned int a, char *base,
					int *countnum, char *result)
{
	a = a / 8;
	if (a >= 8)
	{
		adress8(a, base, countnum, result);
	}
	a = a % 8;
	result[(*countnum)] = base[a];
	(*countnum)++;
}

void	maloccount8(unsigned long long int nbr, int *countnum)
{
	nbr = nbr / 8;
	(*countnum)++;
	if (nbr >= 8)
	{
		maloccount8(nbr, countnum);
	}
}

void	ft_recursive_base8(unsigned int *nbr, char *base,
					int *countnum, char *result)
{
	if ((*nbr) >= 8)
	{
		adress8((*nbr), base, countnum, result);
		result[(*countnum)] = base[(*nbr) % 8];
		(*countnum)++;
	}
	else if ((*nbr) >= 1)
	{
		result[(*countnum)] = base[(*nbr) % 8];
		(*countnum)++;
	}
}

char	*ft_putnbr_base8(unsigned int nbr, char *base)
{
	char					*result;
	int						countnum;

	countnum = 0;
	if (0 == exceptbase8(&base))
	{
		maloccount8(nbr, &countnum);
		result = (char *)malloc(sizeof(char) * ((countnum) + 1 + 1));
		(countnum) = 0;
		if (nbr >= 1)
		{
			ft_recursive_base8(&nbr, base, &countnum, result);
		}
		else if (nbr == 0)
			adress8(nbr, base, &countnum, result);
		result[countnum] = 0;
	}
	else
	{
		result = (char *)malloc(sizeof(char) * (1));
		result[0] = 0;
	}
	return (result);
}
