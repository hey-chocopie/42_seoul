/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setinfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 22:57:07 by hoylee            #+#    #+#             */
/*   Updated: 2020/12/03 01:44:03 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_macos.h"

void	ft_setinfo_key_text(t_info *info)
{
	info->key_a = 0;
	info->key_w = 0;
	info->key_s = 0;
	info->key_d = 0;
	info->key_esc = 0;
	info->no_texture = 0;
	info->so_texture = 0;
	info->we_texture = 0;
	info->ea_texture = 0;
	info->s_texture = 0;
	info->ft_texture = 0;
	info->ct_texture = 0;
	info->f_texture = -1;
	info->c_texture = -1;
	info->texturecount = 8;
	info->texture = 0;
	info->zbuffer = 0;
	info->texture_x_size = 64;
	info->texture_y_size = 64;
}

void	ft_set_basic_info(t_info *info)
{
	info->map.x = 0;
	info->map.y = 0;
	info->map.xx = 0;
	info->map.spr = 0;
	info->map.tab = 0;
	info->pos_x = 22.0;
	info->pos_y = 11.5;
	info->dir_x = 1.0;
	info->dir_y = 0.0;
	info->plane_x = 0.66;
	info->plane_y = 0.0;
	info->width = 600;
	info->height = 600;
	info->movespeed = 0.05;
	info->rotspeed = 0.05;
	info->bmpflag = 0;
	info->err_m = 0;
	info->s_save = 0;
	info->s_tmp = 0;
	info->dot_i = 0;
	info->spriteflag = 0;
	info->map_start_flag = 0;
}

void	ft_setinfo(t_info *info)
{
	ft_set_basic_info(info);
	ft_setinfo_key_text(info);
	info->mlx = mlx_init();
	mlx_get_screen_size(info->mlx,
			&info->winsize.size_x, &info->winsize.size_y);
}
