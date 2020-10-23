/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 21:36:10 by hoylee            #+#    #+#             */
/*   Updated: 2020/08/11 18:09:26 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst,
					const char *restrict src, size_t dstsize)
{
	size_t a;
	a = 0;
	if(!(src))
		return (0);
	while (dstsize > a)
	{
		dst[a] = src[a];
		if (src[a] == 0)
		{
			a++;
			break ;
		}
		a++;
	}
	if (dstsize > 0)
		dst[--a] = 0;
	a = 0;
	while (src[a])
		a++;
	return (a);
}
