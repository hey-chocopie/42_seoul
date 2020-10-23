/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 02:41:16 by hoylee            #+#    #+#             */
/*   Updated: 2020/08/30 17:16:39 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
void		ft_set_s(char **save, char **result, int *count, int *tmp)
{
	*tmp = 0;
	*count = 0;
	*result = 0;
	*save = 0;
}

void		ft_null_s(char **result)
{
	(*result) = (char *)malloc(sizeof(char) * (7));
	(*result)[0] = '(';
	(*result)[1] = 'n';
	(*result)[2] = 'u';
	(*result)[3] = 'l';
	(*result)[4] = 'l';
	(*result)[5] = ')';
	(*result)[6] = 0;
}

void		ft_s(va_list ap, struct person *width)
{
	char		*save;
	char		*result;
	int			count;
	int			tmp;

	ft_set_s(&save, &result, &count, &tmp);
	save = va_arg(ap, char*);
	if (save != 0)
	{
		while (save[count] != 0)
			count++;
		result = (char *)malloc(sizeof(char) * (count + 1));
		while (tmp < count)
		{
			result[tmp] = save[tmp];
			tmp++;
		}
		result[tmp] = 0;
	}
	else if (save == 0)
		ft_null_s(&result);
	ft_string_stprintf(result, width);
}

void		ft_c(va_list ap, struct person *width)
{
	int			save;
	char		*result;
	int			count;
	int			tmp;

	tmp = 0;
	count = 0;
	result = 0;
	save = 0;
	save = va_arg(ap, int);
	if ((save) == 0)
	{
		result = (char *)malloc(sizeof(char) * (1));
		result[0] = '\0';
		(*width).c_null = 1;
	}
	else if (save != 0)
	{
		result = (char *)malloc(sizeof(char) * (2));
		result[0] = (char)save;
		result[1] = 0;
	}
	ft_string_stprintf(result, width);
}
