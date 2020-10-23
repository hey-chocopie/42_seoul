/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 11:13:03 by hoylee            #+#    #+#             */
/*   Updated: 2020/08/12 14:55:19 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	length;
	char	*aa;

	i = (size_t)start;
	length = 0;
	if(!s)
		return (0);
	while (s[i] && (ft_strlen(s) > start))
	{
		if (length >= len)
			break ;
		i++;
		++length;
	}
	if (!(aa = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	i = 0;
	while (i < length)
	{
		aa[i] = s[i + (size_t)start];
		i++;
	}
	aa[i] = '\0';
	return (aa);
}
