/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:58:50 by hoylee            #+#    #+#             */
/*   Updated: 2020/11/28 23:46:08 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_macos.h"

void		set_int_in_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

int			write_bmp_header(int fd, int filesize, t_info *info)
{
	int				i;
	int				tmp;
	unsigned char	bmpfileheader[54];

	i = 0;
	while (i < 54)
		bmpfileheader[i++] = (unsigned char)(0);
	bmpfileheader[0] = (unsigned char)('B');
	bmpfileheader[1] = (unsigned char)('M');
	set_int_in_char(bmpfileheader + 2, filesize);
	bmpfileheader[10] = (unsigned char)(54);
	bmpfileheader[14] = (unsigned char)(40);
	tmp = info->bmpwidth;
	set_int_in_char(bmpfileheader + 18, tmp);
	tmp = info->bmpheigth;
	set_int_in_char(bmpfileheader + 22, tmp);
	bmpfileheader[26] = (unsigned char)(1);
	bmpfileheader[28] = (unsigned char)(32);
	set_int_in_char(bmpfileheader + 38, 5000);
	set_int_in_char(bmpfileheader + 42, 5000);
	return (!(write(fd, bmpfileheader, 54) < 0));
}

void		bmp_pixel_date(int file, t_info *info)
{
	int				x;
	int				y;
	unsigned int	color;

	y = info->bmpheigth;
	x = -1;
	while (--y >= 0)
	{
		while (++x < info->bmpwidth)
		{
			color = info->img.data[(info->img).size_l /
							(info->img.bpp / 8) * y + x];
			write(file, &color, 4);
		}
		x = -1;
	}
}

int			save_bmp(t_info *info)
{
	t_info			*w;
	int				filesize;
	int				file;

	w = info;
	filesize = 2 + 54 + (info->bmpwidth * info->bmpheigth) * 4;
	if (!(file = open("screenshot.bmp", O_CREAT | O_RDWR | O_TRUNC, 0666)))
		return (0);
	if (!write_bmp_header(file, filesize, info))
		return (0);
	bmp_pixel_date(file, w);
	close(file);
	return (1);
}
