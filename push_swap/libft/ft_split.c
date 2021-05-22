/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 01:51:11 by hoylee            #+#    #+#             */
/*   Updated: 2020/12/03 13:09:14 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stringindex(char const *s, char c, int *count, int *flag)
{
	int		i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			*flag = 1;
		else if (*flag == 1)
		{
			(*flag) = 0;
			(*count)++;
		}
	}
}

void	ft_set(int *flag, int *count)
{
	*flag = 1;
	*count = 0;
}

int		ft_aa(char const *s, int *i, char **result, char c)
{
	int		j;
	int		count;
	int		flag;

	ft_set(&flag, &count);
	while (s[++(*i)])
	{
		j = 0;
		if (flag == 1 && s[(*i)] != c)
		{
			while (s[(*i) + j] != c && s[(*i) + j])
				j++;
			if (!(result[count] = (char *)malloc(sizeof(char) * (j + 1))))
				return (3);
			j = -1;
			while (s[(*i) + ++j] != c && s[(*i) + j])
				result[(count)][(j)] = s[(*i) + j];
			result[count][j] = 0;
		}
		if (s[*i] == c)
			flag = 1;
		else if (flag-- == 1)
			count++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		flag;
	int		count;
	char	**result;

	if (s == 0 || c == 0)
		return (0);
	count = 0;
	i = -1;
	j = 0;
	flag = 1;
	ft_stringindex(s, c, &count, &flag);
	if (!(result = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	result[count] = NULL;
	if (ft_aa(s, &i, result, c) == 3)
		return (NULL);
	return (result);
}
