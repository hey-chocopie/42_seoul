/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 23:44:22 by hoylee            #+#    #+#             */
/*   Updated: 2020/12/03 13:08:15 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_startindex(char const *s1, char const *set, int *i, int *j)
{
	while (s1[(*i)])
	{
		while (set[++(*j)])
			if (s1[(*i)] == set[(*j)])
				break ;
		if (set[(*j)] == 0)
			break ;
		(*j) = -1;
		(*i)++;
	}
}

void	ft_finishindex(char const *s1, char const *set, int *i, int *j)
{
	int		save;

	save = *i;
	*j = -1;
	*i = 0;
	while (s1[*i])
		(*i)++;
	while (s1[--(*i)] && *i >= save)
	{
		while (set[++(*j)])
			if (s1[*i] == set[*j])
				break ;
		if (set[*j] == 0)
			break ;
		*j = -1;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		save;
	char	*result;

	if (s1 == 0 || set == 0)
		return (0);
	i = 0;
	j = -1;
	ft_startindex(s1, set, &i, &j);
	save = i;
	ft_finishindex(s1, set, &i, &j);
	if (!(result = (char *)malloc(sizeof(char) * (i - save + 2))))
		return (NULL);
	j = 0;
	while (save < i + 1)
	{
		result[j] = s1[save];
		save++;
		j++;
	}
	result[j] = 0;
	return (result);
}
