/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:42:52 by hoylee            #+#    #+#             */
/*   Updated: 2020/11/27 15:13:19 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_macos.h"

void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	img->img =
	mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
	img->data =
	(int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	ft_basic(t_info *info, int i, int j)
{
	(*info).texture
		[0][info->texture_x_size * j + i] = 65536 * 0 + 254 * 248 + 223;
	(*info).texture
		[1][info->texture_x_size * j + i] = 65536 * 254 + 254 * 236 + 2;
	(*info).texture
		[2][info->texture_x_size * j + i] = 65536 * 239 + 254 * 194 + 233;
	(*info).texture
		[3][info->texture_x_size * j + i] = 65536 * 172 + 254 * 161 + 232;
	(*info).texture
		[5][info->texture_x_size * j + i] = 65536 * 1 + 254 * 42 + 45;
	(*info).texture
		[6][info->texture_x_size * j + i] = 65536 * 110 + 254 * 58 + 108;
}

void	load_hoyleetexture(t_info *info)
{
	int		i;
	int		j;

	i = -1;
	while (++i < info->texture_x_size)
	{
		j = -1;
		while (++j < info->texture_y_size)
		{
			ft_basic(info, i, j);
			if (info->f_texture != -1)
				(*info).
				texture[5][info->texture_x_size * j + i] = info->f_texture;
			if (info->c_texture != -1)
				(*info).
				texture[6][info->texture_x_size * j + i] = info->c_texture;
		}
	}
}

void	map_texture(t_info *info)
{
	t_img	img;

	load_image(info, info->texture[2], "textures/barrel.xpm", &img);
	load_image(info, info->texture[7], "textures/sprite8smallgom.xpm", &img);
	if (info->no_texture != 0)
		load_image(info, info->texture[0], info->no_texture, &img);
	if (info->so_texture != 0)
		load_image(info, info->texture[1], info->so_texture, &img);
	if (info->we_texture != 0)
		load_image(info, info->texture[4], info->we_texture, &img);
	if (info->ea_texture != 0)
		load_image(info, info->texture[3], info->ea_texture, &img);
	if (info->s_texture != 0)
		load_image(info, info->texture[2], info->s_texture, &img);
	if (info->ft_texture != 0)
		load_image(info, info->texture[5], info->ft_texture, &img);
	if (info->ct_texture != 0)
		load_image(info, info->texture[6], info->ct_texture, &img);
	if (info->s_texture != 0)
		load_image(info, info->texture[7], info->s_texture, &img);
}

void	ft_texture_input(t_info *info)
{
	load_hoyleetexture(info);
	map_texture(info);
}
