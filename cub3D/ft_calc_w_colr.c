/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_w_colr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:00:49 by hoylee            #+#    #+#             */
/*   Updated: 2020/11/28 20:33:46 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_macos.h"

void	ft_calc_w_set_pstexture(t_info *info)
{
	if (info->cwall.side == 0)
		info->cwall.wall_x =
			info->posY + info->cwall.perpwalldist * info->cwall.raydir_xy[1];
	else
		info->cwall.wall_x =
			info->posX + info->cwall.perpwalldist * info->cwall.raydir_xy[0];
	info->cwall.wall_x -= floor(info->cwall.wall_x);
	info->cwall.tex_x =
		(int)(info->cwall.wall_x * (double)info->texture_x_size);
	if (info->cwall.side == 0 && info->cwall.raydir_xy[0] > 0)
		info->cwall.tex_x = info->texture_x_size - info->cwall.tex_x - 1;
	if (info->cwall.side == 1 && info->cwall.raydir_xy[1] < 0)
		info->cwall.tex_x = info->texture_x_size - info->cwall.tex_x - 1;
	info->cwall.step = 1.0 * info->texture_y_size / info->cwall.lineheight;
	info->cwall.texpos =
		(info->cwall.drawstart - info->height / 2 + info->cwall.lineheight / 2)
		* info->cwall.step;
}

void	ft_calc_w_put_colr(t_info *info, int x)
{
	int j;
	int color;

	j = info->cwall.drawstart;
	while (j < info->cwall.drawend)
	{
		info->cwall.tex_y =
		(int)info->cwall.texpos & (info->texture_y_size - 1);
		info->cwall.texpos += info->cwall.step;
		color = info->texture[info->cwall.texnum]
		[info->texture_y_size * info->cwall.tex_y + info->cwall.tex_x];
		if (info->cwall.side == 1)
			color = (color / 2) & 8355711;
		info->buf[j][x] = color;
		j++;
	}
}

void	ft_calc_w_colr(t_info *info, int x)
{
	ft_calc_w_set_pstexture(info);
	ft_calc_w_put_colr(info, x);
}
