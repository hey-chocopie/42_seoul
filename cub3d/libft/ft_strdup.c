/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 01:57:48 by hoylee            #+#    #+#             */
/*   Updated: 2020/07/22 16:40:45 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		aa[0] = 0;
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
