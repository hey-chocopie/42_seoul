/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:44:42 by hoylee            #+#    #+#             */
/*   Updated: 2020/07/01 17:45:08 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst,
			const void *restrict src, int c, size_t n)
{
	unsigned int cmp;

	cmp = 0;
	while (n > cmp)
	{
		((unsigned char *)dst)[cmp] = ((unsigned char *)src)[cmp];
		if (((unsigned char *)dst)[cmp] == (unsigned char)c)
			return (dst + cmp + 1);
		cmp++;
	}
	return (0);
}
