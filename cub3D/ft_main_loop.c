/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:12:24 by hoylee            #+#    #+#             */
/*   Updated: 2020/11/28 22:31:14 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_macos.h"

void	calc(t_info *info)
{
	ft_calc_fc(info);
	ft_calc_wall(info);
	ft_cal_sp(info);
}

void	draw(t_info *info)
{
	int y;
	int x;

	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			info->img.data[(info->img).size_l
				/ (info->img.bpp / 8) * y + x] = info->buf[y][x];
			x++;
		}
		y++;
	}
	if (info->bmpflag == 0)
		save_bmp(info);
	info->bmpflag = 1;
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
	mlx_string_put(info->mlx, info->win,
		20, (*info).height - 20, 16711680, "hoylee_cub3d");
}

void	key_update_da_esc(t_info *info, double *olddir_x, double *oldplane_x)
{
	(*olddir_x) = info->dir_x;
	(*oldplane_x) = info->plane_x;
	if (info->key_d)
	{
		info->dir_x = info->dir_x * cos(-info->rotSpeed)
						- info->dir_y * sin(-info->rotSpeed);
		info->dir_y = (*olddir_x) * sin(-info->rotSpeed)
						+ info->dir_y * cos(-info->rotSpeed);
		info->plane_x = info->plane_x * cos(-info->rotSpeed)
						- info->plane_y * sin(-info->rotSpeed);
		info->plane_y = (*oldplane_x) * sin(-info->rotSpeed)
						+ info->plane_y * cos(-info->rotSpeed);
	}
	if (info->key_a)
	{
		info->dir_x = info->dir_x * cos(info->rotSpeed)
						- info->dir_y * sin(info->rotSpeed);
		info->dir_y = (*olddir_x) * sin(info->rotSpeed)
						+ info->dir_y * cos(info->rotSpeed);
		info->plane_x = info->plane_x * cos(info->rotSpeed)
						- info->plane_y * sin(info->rotSpeed);
		info->plane_y = (*oldplane_x) * sin(info->rotSpeed)
						+ info->plane_y * cos(info->rotSpeed);
	}
}

void	key_update_ws(t_info *info)
{
	if (info->key_w)
	{
		if (!info->fullmap[(int)(info->pos_x + info->dir_x
					* info->moveSpeed)][(int)(info->pos_y)])
			info->pos_x += info->dir_x * info->moveSpeed;
		if (!info->fullmap
			[(int)(info->pos_x)][(int)(info->pos_y + info->dir_y
					* info->moveSpeed)])
			info->pos_y += info->dir_y * info->moveSpeed;
	}
	if (info->key_s)
	{
		if (!info->fullmap[(int)(info->pos_x - info->dir_x
					* info->moveSpeed)][(int)(info->pos_y)])
			info->pos_x -= info->dir_x * info->moveSpeed;
		if (!info->fullmap
			[(int)(info->pos_x)][(int)(info->pos_y - info->dir_y
					* info->moveSpeed)])
			info->pos_y -= info->dir_y * info->moveSpeed;
	}
	if (info->key_esc)
		exit(0);
}

int		ft_main_loop(t_info *info)
{
	double olddir_x;
	double oldplane_x;

	olddir_x = 0;
	oldplane_x = 0;
	calc(info);
	draw(info);
	key_update_ws(info);
	key_update_da_esc(info, &olddir_x, &oldplane_x);
	return (0);
}
