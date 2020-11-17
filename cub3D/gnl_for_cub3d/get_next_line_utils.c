/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 21:31:56 by hoylee            #+#    #+#             */
/*   Updated: 2020/07/26 15:26:53 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*aa;

	i = 0;
	while (s1[i])
		i++;
	if (!(aa = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	if (!(s1[i]))
	{
		(aa[0]) = 0;
		return (aa);
	}
	while (s1[i])
	{
		aa[i] = s1[i];
		i++;
	}
	aa[i] = 0;
	return (aa);
}

void	ft_length(int *i, int *j, char const *s1, char const *s2)
{
	while (s1[*i])
		(*i)++;
	while (s2[*j])
		(*j)++;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
		return (!s1 ? ft_strdup(s2) : ft_strdup(s1));
	i = 0;
	j = 0;
	ft_length(&i, &j, s1, s2);
	if (!(result = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		result[i] = s1[i];
	while (s2[++j])
		result[i++] = s2[j];
	result[i] = 0;
	return (result);
}
