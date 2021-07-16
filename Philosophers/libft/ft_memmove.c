/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 16:43:22 by hoylee            #+#    #+#             */
/*   Updated: 2020/07/11 20:05:43 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if ((dst == 0 && src == 0) || len == 0)
		return (dst);
	if (dst > src)
	{
		while (i < len)
			i++;
		i--;
		while (i >= 0)
		{
			((char *)dst)[i] = ((char *)src)[i];
			if (i == 0)
				break ;
			i--;
		}
	}
	else
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	return (dst);
}
