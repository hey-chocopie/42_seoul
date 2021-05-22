/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 19:49:53 by hoylee            #+#    #+#             */
/*   Updated: 2020/07/06 16:22:30 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned	int a;

	a = 0;
	while (a < n && sizeof(((const unsigned char *)s)[a]) == 1)
	{
		if (((const unsigned char *)s)[a] == (unsigned char)c)
		{
			return (((unsigned char *)s) + ((int)a));
		}
		a++;
	}
	return (0);
}
