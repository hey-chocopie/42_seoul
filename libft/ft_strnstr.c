/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 13:04:20 by hoylee            #+#    #+#             */
/*   Updated: 2020/07/12 14:52:16 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (!*needle)
		return ((char*)haystack);
	while (haystack[i] && (len > i))
	{
		j = 0;
		if (needle[j] == 0)
			return ((char *)haystack);
		while ((needle[j] != 0) &&
				((haystack[i + j] == needle[j]) && len > i + j))
		{
			j++;
		}
		if (needle[j] == 0)
			return (((char *)haystack) + i);
		i++;
	}
	return (NULL);
}
