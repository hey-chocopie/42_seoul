/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 01:38:06 by hoylee            #+#    #+#             */
/*   Updated: 2020/07/03 02:02:16 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*aa;
	size_t	b;

	b = 0;
	if (!(aa = (char *)malloc(size * count)))
		return (NULL);
	while (b < size * count)
	{
		aa[b] = 0;
		b++;
	}
	return (aa);
}
