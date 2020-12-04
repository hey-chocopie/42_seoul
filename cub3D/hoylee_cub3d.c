/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hoylee_cub3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:30:20 by hoylee            #+#    #+#             */
/*   Updated: 2020/12/03 14:45:29 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_macos.h"
#include "./libft/libft.h"

int		ft_args_argv_check(t_info *info, int args, char **argv)
{
	if (args < 2 || args >= 4)
	{
		ft_printf("check args\n%s : %d\n", strerror(22), 22);
		return (-1);
	}
	if (!ft_strncmp(argv[2], "--save", 6))
		info->bmpflag = 1;
	else if (args == 3)
	{
		ft_printf("check second argument\n%s : %d\n", strerror(22), 22);
		return (-1);
	}
	return (0);
}

int		ft_dot(t_info *info, char *text, int space_i)
{
	int		errno;

	errno = 0;
	if (0 > (errno = dot_cub_test(&text, info, space_i)))
	{
		ft_input_texture_free(info);
		if (info->err_m != 0)
			ft_printf("%s :%d", strerror(info->err_m), info->err_m * (1));
		else
			ft_printf("%s : %d", strerror(-errno), errno * (-1));
		exit(-1);
	}
	return (0);
}

int		ft_mapparse(t_info *info, char **argv)
{
	int		fd;
	char	*text;
	int		check;
	int		space_i;
	char	*aa;

	check = 1;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (tool_fd_return());
	while (check != 0 && check != -1)
	{
		space_i = 0;
		check = get_next_line(fd, &text);
		while (text[space_i] == ' ')
			space_i++;
		aa = text;
		text = space_i + text;
		if (-1 == ft_dot(info, text, space_i))
			return (-1);
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
}

int		main(int args, char **argv)
{
	t_info	info;

	ft_setinfo(&info);
	if (-1 == ft_args_argv_check(&info, args, argv)
		|| -1 == ft_mapparse(&info, argv))
		exit(-1);
	ft_pos(&info);
	if (-1 == ft_map_info(&info)
		|| -1 == ft_buf_texture_malloc(&info))
		exit(-1);
	ft_texture_input(&info);
	ft_display_set(&info);
	mlx_loop_hook(info.mlx, &ft_main_loop, &info);
	ft_keypress(&info);
	mlx_loop(info.mlx);
	mlx_clear_window(info.mlx, info.win);
}
