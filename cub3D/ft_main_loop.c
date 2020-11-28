/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:12:24 by hoylee            #+#    #+#             */
/*   Updated: 2020/11/27 18:42:31 by hoylee           ###   ########.fr       */
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
	(*olddir_x) = info->dirX;
	(*oldplane_x) = info->planeX;
	if (info->key_d)
	{
		info->dirX = info->dirX * cos(-info->rotSpeed)
						- info->dirY * sin(-info->rotSpeed);
		info->dirY = (*olddir_x) * sin(-info->rotSpeed)
						+ info->dirY * cos(-info->rotSpeed);
		info->planeX = info->planeX * cos(-info->rotSpeed)
						- info->planeY * sin(-info->rotSpeed);
		info->planeY = (*oldplane_x) * sin(-info->rotSpeed)
						+ info->planeY * cos(-info->rotSpeed);
	}
	if (info->key_a)
	{
		info->dirX = info->dirX * cos(info->rotSpeed)
						- info->dirY * sin(info->rotSpeed);
		info->dirY = (*olddir_x) * sin(info->rotSpeed)
						+ info->dirY * cos(info->rotSpeed);
		info->planeX = info->planeX * cos(info->rotSpeed)
						- info->planeY * sin(info->rotSpeed);
		info->planeY = (*oldplane_x) * sin(info->rotSpeed)
						+ info->planeY * cos(info->rotSpeed);
	}
}

void	key_update_ws(t_info *info)
{
	if (info->key_w)
	{
		if (!info->fullmap[(int)(info->posX + info->dirX
					* info->moveSpeed)][(int)(info->posY)])
			info->posX += info->dirX * info->moveSpeed;
		if (!info->fullmap
			[(int)(info->posX)][(int)(info->posY + info->dirY
					* info->moveSpeed)])
			info->posY += info->dirY * info->moveSpeed;
	}
	if (info->key_s)
	{
		if (!info->fullmap[(int)(info->posX - info->dirX
					* info->moveSpeed)][(int)(info->posY)])
			info->posX -= info->dirX * info->moveSpeed;
		if (!info->fullmap
			[(int)(info->posX)][(int)(info->posY - info->dirY
					* info->moveSpeed)])
			info->posY -= info->dirY * info->moveSpeed;
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
