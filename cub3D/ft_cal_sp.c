/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cal_sp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:45:44 by hoylee            #+#    #+#             */
/*   Updated: 2020/11/27 18:01:32 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_macos.h"

void	ft_calc_sp_set(t_info *info, int *sp_order, int i)
{
	info->spr.sprite_x = info->s_save[sp_order[i]].x - info->posX;
	info->spr.sprite_y = info->s_save[sp_order[i]].y - info->posY;
	info->spr.invdet = 1.0 /
	(info->planeX * info->dirY - info->dirX * info->planeY);
	info->spr.transform_x = info->spr.invdet *
	(info->dirY * info->spr.sprite_x - info->dirX * info->spr.sprite_y);
	info->spr.transform_y = info->spr.invdet *
	(-info->planeY * info->spr.sprite_x + info->planeX * info->spr.sprite_y);
	info->spr.screen_x = (int)((info->width / 2) *
		(1 + info->spr.transform_x / info->spr.transform_y));
}

void	ft_calc_sp_ps_draw(t_info *info, int *sp_order, int i, int *vmove)
{
	(*vmove) = 0.0;
	if (info->spriteflag < 7000000
		&& info->s_save[sp_order[i]].texture == 2 && (info->s_texture == 0))
		(*vmove) = 0;
	else if (info->spriteflag >= 7000000 && info->spriteflag <= 10000000
		&& info->s_save[sp_order[i]].texture == 2 && (info->s_texture == 0))
		(*vmove) = 150;
	info->spr.v_movescreen = (int)((*vmove) / info->spr.transform_y);
	info->spr.sp_height = (int)fabs((info->height / info->spr.transform_y) / 1);
	info->spr.drawstart_y =
		-info->spr.sp_height / 2 + info->height / 2 + info->spr.v_movescreen;
	if (info->spr.drawstart_y < 0)
		info->spr.drawstart_y = 0;
	info->spr.drawend_y =
		info->spr.sp_height / 2 + info->height / 2 + info->spr.v_movescreen;
	if (info->spr.drawend_y >= info->height)
		info->spr.drawend_y = info->height - 1;
	info->spr.sprite_width =
		(int)fabs((info->height / info->spr.transform_y) / 1);
	info->spr.drawstart_x = -info->spr.sprite_width / 2 + info->spr.screen_x;
	if (info->spr.drawstart_x < 0)
		info->spr.drawstart_x = 0;
	info->spr.drawend_x = info->spr.sprite_width / 2 + info->spr.screen_x;
	if (info->spr.drawend_x >= info->width)
		info->spr.drawend_x = info->width - 1;
}

int		ft_calc_sp_input(t_info *info, int i, int *sp_order, int y)
{
	int d;
	int tex_y;
	int color;

	d = (y - info->spr.v_movescreen) * 256
		- info->height * 128 + info->spr.sp_height * 128;
	tex_y = ((d * info->texture_y_size) / info->spr.sp_height) / 256;
	color = info->texture
			[info->s_save
		[sp_order[i]].texture][info->texture_x_size * tex_y + info->spr.tex_x];
	if (info->spriteflag < 7000000 && info->s_save[sp_order[i]].texture == 2)
	{
		color = info->texture[info->s_save
		[sp_order[i]].texture][info->texture_x_size * tex_y + info->spr.tex_x];
		info->spriteflag++;
	}
	else if (info->s_save[sp_order[i]].texture == 2)
	{
		color =
			info->texture[7][info->texture_x_size * tex_y + info->spr.tex_x];
		info->spriteflag++;
		if (info->spriteflag > 10000000)
			info->spriteflag = 0;
	}
	return (color);
}

void	ft_calc_sp_draw(t_info *info, int *sp_order, int i)
{
	int stripe;
	int color;
	int y;

	stripe = info->spr.drawstart_x;
	while (stripe < info->spr.drawend_x)
	{
		info->spr.tex_x = (int)((256 *
			(stripe - (-info->spr.sprite_width / 2 + info->spr.screen_x))
		* info->texture_x_size / info->spr.sprite_width) / 256);
		if (info->spr.transform_y > 0 &&
			info->spr.transform_y < info->zBuffer[stripe])
		{
			y = info->spr.drawstart_y;
			while (y < info->spr.drawend_y)
			{
				color = ft_calc_sp_input(info, i, sp_order, y);
				if ((color & 0x00FFFFFF) != 0)
					info->buf[y][stripe] = color;
				y++;
			}
		}
		stripe++;
	}
}

int		ft_cal_sp(t_info *info)
{
	int		sp_order[info->map.spr];
	int		i;
	int		vmove;

	i = 0;
	ft_calc_sp_info(info, sp_order);
	while (i < info->map.spr)
	{
		ft_calc_sp_set(info, sp_order, i);
		ft_calc_sp_ps_draw(info, sp_order, i, &vmove);
		ft_calc_sp_draw(info, sp_order, i);
		i++;
	}
	return (0);
}
