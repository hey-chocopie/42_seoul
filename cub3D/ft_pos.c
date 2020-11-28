/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 23:40:22 by hoylee            #+#    #+#             */
/*   Updated: 2020/11/28 23:41:11 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_macos.h"

void	ft_pos(t_info *info)
{
	char	c;
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < info->map.y)
	{
		while (++j < info->map.x)
		{
			c = info->map.tab[i][j];
			if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
			{
				info->pos_y = (double)j + 0.5;
				info->pos_x = (double)i + 0.5;
				info->dir_y = (c == 'E' || c == 'W') ? 1 : 0;
				info->dir_y *= (c == 'W') ? -1 : 1;
				info->dir_x = (c == 'S' || c == 'N') ? 1 : 0;
				info->dir_x *= (c == 'N') ? -1 : 1;
			}
		}
		j = -1;
	}
	info->plane_x = info->dir_y * (0.66);
	info->plane_y = info->dir_x * (-0.66);
}
