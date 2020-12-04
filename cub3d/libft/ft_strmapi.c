/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 21:21:45 by hoylee            #+#    #+#             */
/*   Updated: 2020/12/03 13:07:39 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		a;
	char	*result;

	if (s == 0 || f == 0)
		return (0);
	a = 0;
	while (s[a])
		a++;
	if (!(result = (char *)malloc(sizeof(char) * (a + 1))))
		return (NULL);
	a = 0;
	while (s[a])
	{
		result[a] = (*f)(a, s[a]);
		a++;
	}
	result[a] = 0;
	return (result);
}
