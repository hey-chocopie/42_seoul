/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 17:33:53 by hoylee            #+#    #+#             */
/*   Updated: 2020/12/03 13:03:29 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_check(const char *str, int *manus, int *a)
{
	while ((str[*a] >= 9 && str[*a] <= 13) || str[*a] == 32)
		(*a)++;
	if (str[*a] == '+' || str[*a] == '-')
	{
		if (str[*a] == '-')
			(*manus) = -1;
		(*a)++;
	}
}

void	ft_atoiset(int *flag, int *manus, long long int *result, int *a)
{
	(*flag) = 1;
	(*result) = 0;
	(*a) = 0;
	(*manus) = 1;
}

int		ft_atoi(const char *str)
{
	int				a;
	long long int	result;
	int				manus;
	int				flag;

	ft_atoiset(&flag, &manus, &result, &a);
	ft_check(str, &manus, &a);
	while (str[a] >= '0' && str[a] <= '9')
	{
		if (result >= 214748365 || (result >= 214748364 &&
						(str[a] == '8' || str[a] == '9')))
			return (-1);
		if (result <= -214748365 || (result <= -214748364 && (str[a] == '9')))
			return (0);
		if (result == 0)
			result = str[a] - '0';
		else if (a > 0 && result > 0)
			result = result * 10 + (str[a] - '0');
		else if (a > 0 && result < 0)
			result = result * 10 - (str[a] - '0');
		if (result != 0 && (manus == -1 && (flag++) == 1))
			result = result * manus;
		a++;
	}
	return (result);
}
