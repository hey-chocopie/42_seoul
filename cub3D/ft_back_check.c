/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 20:01:04 by hoylee            #+#    #+#             */
/*   Updated: 2020/12/02 20:13:00 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_macos.h"

int		ft_back_check(t_info *info)
{
	int		i;
	int		j;

	i = 0;
	while (i < info->map.y)
	{
		j = info->map.x - 1;
		while (j >= 0 && info->map.tab[i][j] == ' ')
			j--;
		if (j == -1 || info->map.tab[i][j] != '1')
			return (-1);
		i++;
	}
	return (0);
}
