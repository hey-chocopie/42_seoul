/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:20:14 by hoylee            #+#    #+#             */
/*   Updated: 2020/11/28 22:31:13 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_macos.h"

void	ft_calc_w_set(t_info *info, int x)
{
	info->cwall.raydir_xy[0] =
	info->dir_x + info->plane_x * (2 * x / (double)info->width - 1);
	info->cwall.raydir_xy[1] =
	info->dir_y + info->plane_y * (2 * x / (double)info->width - 1);
	info->cwall.map_xy[0] = (int)info->pos_x;
	info->cwall.map_xy[1] = (int)info->pos_y;
	info->cwall.deltadist_xy[0] = fabs(1 / info->cwall.raydir_xy[0]);
	info->cwall.deltadist_xy[1] = fabs(1 / info->cwall.raydir_xy[1]);
	info->cwall.hit = 0;
}

void	ft_calc_w_step_set_info(t_info *info)
{
	if (info->cwall.raydir_xy[0] < 0)
	{
		info->cwall.step_xy[0] = -1;
		info->cwall.sidedist_xy[0] =
		(info->pos_x - info->cwall.map_xy[0]) * info->cwall.deltadist_xy[0];
	}
	else
	{
		info->cwall.step_xy[0] = 1;
		info->cwall.sidedist_xy[0] = (info->cwall.map_xy[0] + 1.0 - info->pos_x)
		* info->cwall.deltadist_xy[0];
	}
	if (info->cwall.raydir_xy[1] < 0)
	{
		info->cwall.step_xy[1] = -1;
		info->cwall.sidedist_xy[1] =
		(info->pos_y - info->cwall.map_xy[1])
		* info->cwall.deltadist_xy[1];
	}
	else
	{
		info->cwall.step_xy[1] = 1;
		info->cwall.sidedist_xy[1] = (info->cwall.map_xy[1] + 1.0 - info->pos_y)
		* info->cwall.deltadist_xy[1];
	}
}

void	ft_calc_w_ps_map(t_info *info)
{
	while (info->cwall.hit == 0)
	{
		if (info->cwall.sidedist_xy[0] < info->cwall.sidedist_xy[1])
		{
			info->cwall.sidedist_xy[0] += info->cwall.deltadist_xy[0];
			info->cwall.map_xy[0] += info->cwall.step_xy[0];
			info->cwall.side = 0;
		}
		else
		{
			info->cwall.sidedist_xy[1] += info->cwall.deltadist_xy[1];
			info->cwall.map_xy[1] += info->cwall.step_xy[1];
			info->cwall.side = 1;
		}
		if (info->fullmap[info->cwall.map_xy[0]][info->cwall.map_xy[1]] > 0)
			info->cwall.hit = 1;
	}
	if (info->cwall.side == 0)
		info->cwall.perpwalldist =
		(info->cwall.map_xy[0] - info->pos_x +
		(1 - info->cwall.step_xy[0]) / 2) / info->cwall.raydir_xy[0];
	else
		info->cwall.perpwalldist =
		(info->cwall.map_xy[1] - info->pos_y +
		(1 - info->cwall.step_xy[1]) / 2) / info->cwall.raydir_xy[1];
}

void	ft_calc_w_set_psline(t_info *info)
{
	info->cwall.lineheight = (int)(info->height / info->cwall.perpwalldist);
	info->cwall.drawstart = -info->cwall.lineheight / 2 + info->height / 2;
	if (info->cwall.drawstart < 0)
		info->cwall.drawstart = 0;
	info->cwall.drawend = info->cwall.lineheight / 2 + info->height / 2;
	if (info->cwall.drawend >= info->height)
		info->cwall.drawend = info->height - 1;
	info->cwall.texnum =
		info->fullmap[info->cwall.map_xy[0]][info->cwall.map_xy[1]] - 1;
	if (info->cwall.map_xy[0] == 0)
		info->cwall.texnum = 0;
	if (info->cwall.map_xy[0] == info->map.y - 1)
		info->cwall.texnum = 1;
	if (info->cwall.map_xy[1] == 0)
		info->cwall.texnum = 4;
	if (info->cwall.map_xy[1] == info->map.x - 1)
		info->cwall.texnum = 3;
}

void	ft_calc_wall(t_info *info)
{
	int x;

	x = 0;
	while (x < info->width)
	{
		ft_calc_w_set(info, x);
		ft_calc_w_step_set_info(info);
		ft_calc_w_ps_map(info);
		ft_calc_w_set_psline(info);
		ft_calc_w_colr(info, x);
		info->zBuffer[x] = info->cwall.perpwalldist;
		x++;
	}
}
