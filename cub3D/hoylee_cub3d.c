/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hoylee_cub3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:30:20 by hoylee            #+#    #+#             */
/*   Updated: 2020/11/28 23:44:12 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_macos.h"

int		ft_dot(t_info *info, char *text)
{
	int		errno;

	errno = 0;
	if (0 > (errno = dot_cub_test(&text, info)))
	{
		ft_input_texture_free(info);
		if (info->err_m != 0)
			ft_printf("%d : %s", info->err_m * (-1), strerror(info->err_m));
		ft_printf("%d : %s", errno * (-1), strerror(errno));
		return (-1);
	}
	return (0);
}

int		ft_mapparse(t_info *info)
{
	int		fd;
	char	*text;
	int		check;
	int		i;
	char	*aa;

	i = 0;
	check = 1;
	fd = open("./map/2.cub", O_RDONLY);
	while (check != 0 && check != -1)
	{
		check = get_next_line(fd, &text);
		while (text[i] == ' ')
			i++;
		text = i + text;
		if (-1 == ft_dot(info, text))
			return (-1);
		aa = text;
		free(aa);
	}
	close(fd);
	return (0);
}

void	ft_display_set(t_info *info)
{
	info->win = mlx_new_window(info->mlx, info->width, info->height, "mlx");
	info->img.img = mlx_new_image(info->mlx, info->width, info->height);
	info->img.data = (int *)mlx_get_data_addr(info->img.img,
				&info->img.bpp, &info->img.size_l, &info->img.endian);
//	mlx_clear_window(info->mlx, info->win);
}

int		main(void)
{
	t_info	info;

	ft_setinfo(&info);
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
}
