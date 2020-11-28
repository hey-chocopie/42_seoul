/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_sp_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:55:02 by hoylee            #+#    #+#             */
/*   Updated: 2020/11/28 22:30:19 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_macos.h"

void	sort_order(t_pair *orders, int amount)
{
	t_pair	tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < amount)
	{
		j = 0;
		while (j < amount - 1)
		{
			if (orders[j].first > orders[j + 1].first)
			{
				tmp.first = orders[j].first;
				tmp.second = orders[j].second;
				orders[j].first = orders[j + 1].first;
				orders[j].second = orders[j + 1].second;
				orders[j + 1].first = tmp.first;
				orders[j + 1].second = tmp.second;
			}
			j++;
		}
		i++;
	}
}

int		sortsprites(t_info *info, int *order, double *dist, int amount)
{
	int		i;
	t_pair	*sprites;

	i = 0;
	if (!(sprites = (t_pair*)malloc(sizeof(t_pair) * amount)))
	{
		info->err_m = -12;
		return (-1);
	}
	while (i < amount)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
		i++;
	}
	sort_order(sprites, amount);
	i = 0;
	while (i < amount)
	{
		dist[i] = sprites[amount - i - 1].first;
		order[i] = sprites[amount - i - 1].second;
		i++;
	}
	free(sprites);
	return (0);
}

int		ft_calc_sp_info(t_info *info, int *sp_order)
{
	int		i;
	double	sp_distance[info->map.spr];

	i = 0;
	while (i < info->map.spr)
	{
		sp_order[i] = i;
		sp_distance[i] = ((info->pos_x - info->s_save[i].x) *
		(info->pos_x - info->s_save[i].x) + (info->pos_y - info->s_save[i].y)
		* (info->pos_y - info->s_save[i].y));
		i++;
	}
	if (-1 == sortsprites(info, sp_order, sp_distance, info->map.spr))
		return (-1);
	return (0);
}
