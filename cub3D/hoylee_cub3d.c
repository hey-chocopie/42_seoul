/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hoylee_cub3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:30:20 by hoylee            #+#    #+#             */
/*   Updated: 2020/11/28 20:41:54 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_macos.h"

void	key_update(t_info *info);


void	ft_pos(t_info *info)
{
	char	c;
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < info->map.y)
	{
		while (++j < info->map.x)
		{
			c = info->map.tab[i][j];
			if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
			{
				info->posY = (double)j + 0.5;
				info->posX = (double)i + 0.5;
				info->dirY = (c == 'E' || c == 'W') ? 1 : 0;
				info->dirY *= (c == 'W') ? -1 : 1;
				info->dirX = (c == 'S' || c == 'N') ? 1 : 0;
				info->dirX *= (c == 'N') ? -1 : 1;
			}
		}
		j = -1;
	}
	info->planeX = info->dirY * (0.66);
	info->planeY = info->dirX * (-0.66);
}


void ft_setinfo(t_info *info)
{
	info->map.x = 0;
	info->map.y = 0;

	info->map.spr = 0;
	info->map.tab = NULL;
	info->no_texture = 0;
	info->so_texture = 0;
	info->we_texture = 0;
	info->ea_texture = 0;
	info->s_texture = 0;
	info->ft_texture = 0;
	info->ct_texture = 0;

	info->f_texture = -1;
	info->c_texture = -1;

	info->bmpflag = 0;
	info->posX = 22.0;
	info->posY = 11.5;
	info->dirX = 1.0;
	info->dirY = 0.0;
	info->planeX = 0.66;
	info->planeY = 0.0;
	info->key_a = 0;
	info->key_w = 0;
	info->key_s = 0;
	info->key_d = 0;
	info->key_esc = 0;

	info->err_m = 0;
	info->texturecount = 8;
	info->texture = 0;
	info->zBuffer = 0;

	info->width = 600;
	info->height = 600;

	info->moveSpeed = 0.05;
	info->rotSpeed = 0.05;

	info->texture_x_size = 64;
	info->texture_y_size = 64;
	info->s_save = 0;
	info->s_tmp = 0;
	info->dot_i = 0;
	info->spriteflag = 0;
}

int ft_mapparse(t_info *info)
{
	int fd;
	char *text;
	int check;
	char *aa;
	int i;
	int errno;
	errno = 0;
	i = 0;
	check = 1;
    fd=open("./map/2.cub",O_RDONLY);
	while (check != 0 && check != -1 )
	{
		check = get_next_line(fd, &text);
		while (text[i] == ' ')
			i++;
		text = i + text;	
		aa = text;
		if (0 > (errno = dot_cub_test(&text, info)))
		{
			printf("dural;");
			ft_input_texture_free(info);
			if (info->err_m != 0)
				ft_printf("%d : %s", info->err_m*(-1), strerror(info->err_m));
			ft_printf("%d : %s" , errno*(-1),  strerror(errno));
			return (-1);
		}
		free(aa);
	}
	close(fd);

	return (0);
}



void ft_display_set(t_info *info)
{
	info->win = mlx_new_window(info->mlx,  info->width, info->height,"mlx");
	info->img.img = mlx_new_image(info->mlx,  info->width ,info->height);
	info->img.data = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp, &info->img.size_l, &info->img.endian);

//	mlx_clear_window(info->mlx, info->win);
}

int	main(void)
{
	t_info info;
	ft_setinfo(&info);

	info.mlx = mlx_init();
	mlx_get_screen_size(info.mlx, &info.winsize.size_x, &info.winsize.size_y);
	if (-1 == ft_mapparse(&info))
		return (-1);
	ft_pos(&info);
	if (-1 == ft_map_info(&info) || -1 == ft_buf_texture_malloc(&info))
		return (-1);
	ft_texture_input(&info);
	ft_display_set(&info);
	mlx_loop_hook(info.mlx, &ft_main_loop, &info);
	ft_keypress(&info);
	mlx_loop(info.mlx);
	printf("1");
}
