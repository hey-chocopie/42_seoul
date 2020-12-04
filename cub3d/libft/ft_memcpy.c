/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 14:26:53 by hoylee            #+#    #+#             */
/*   Updated: 2020/07/13 20:38:03 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned	int	a;

	a = 0;
	if (src == 0 && dst == 0)
		return (dst);
	while (a < n)
	{
		((char *)dst)[a] = ((const char *)src)[a];
		a++;
	}
	return (dst);
}
