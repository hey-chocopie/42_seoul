/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 23:40:22 by hoylee            #+#    #+#             */
/*   Updated: 2020/12/03 01:52:14 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_macos.h"

void	ft_pos_fail(t_info *info)
{
	ft_input_texture_free(info);
	ft_printf("S,W,E,N check\n");
	ft_printf("%s : %d", strerror(22), 22);
	exit(-1);
}

void	ft_pos_info(t_info *info, char c, int i, int j)
{
	info->pos_y = (double)j + 0.5;
	info->pos_x = (double)i + 0.5;
	info->dir_y = (c == 'E' || c == 'W') ? 1 : 0;
	info->dir_y *= (c == 'W') ? -1 : 1;
	info->dir_x = (c == 'S' || c == 'N') ? 1 : 0;
	info->dir_x *= (c == 'N') ? -1 : 1;
	info->map.tab[i][j] = '0';
}

void	ft_pos(t_info *info)
{
	char	c;
	int		i;
	int		j;
	int		flag;

	i = -1;
	j = -1;
	flag = 0;
	while (++i < info->map.y)
	{
		while (++j < info->map.x)
		{
			c = info->map.tab[i][j];
			if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
			{
				ft_pos_info(info, c, i, j);
				if (++flag > 1)
					ft_pos_fail(info);
			}
		}
		j = -1;
	}
	info->plane_x = info->dir_y * (0.66);
	info->plane_y = info->dir_x * (-0.66);
}
