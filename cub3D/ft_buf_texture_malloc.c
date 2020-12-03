/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf_texture_malloc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 02:17:12 by hoylee            #+#    #+#             */
/*   Updated: 2020/12/02 22:51:38 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_macos.h"

int		ft_texture_malloc(t_info *info, int i)
{
	int		j;

	if (!(info->texture = (int **)malloc(sizeof(int *) * info->texturecount)))
	{
		ft_printf("info->texture memorry fail\n");
		ft_tool_mem_free(info, 1);
		exit(-1);
	}
	i = -1;
	while (++i < info->texturecount)
		if (!(info->texture[i] = (int *)malloc(sizeof(int)
			* (info->texture_y_size * info->texture_x_size))))
		{
			ft_printf("info->textire[i] ,memorry fail\n");
			ft_tool_mem_free(info, 1);
			exit(-1);
		}
	i = -1;
	while (++i < info->texturecount)
	{
		j = -1;
		while (++j < info->texture_y_size)
			info->texture[i][j] = 0;
	}
	return (0);
}

int		ft_buf_set(t_info *info)
{
	int		i;
	int		j;

	i = 0;
	while (i < info->height)
	{
		j = 0;
		while (j < info->width)
		{
			info->buf[i][j] = 0;
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_malloc_zbuffer(t_info *info)
{
	if (!(info->zbuffer = (double *)malloc(sizeof(double) * (info->width))))
	{
		ft_printf("zbuffer memorry fail\n");
		ft_tool_mem_free(info, 1);
		exit(-1);
	}
	return (0);
}

void	ft_buf_malloc(t_info *info)
{
	int i;

	i = 0;
	if (!(info->buf = (int **)malloc(sizeof(int *) * info->height)))
	{
		ft_printf("buf memorry fail\n");
		ft_input_texture_free(info);
		ft_printf("%d : %s", 12, strerror(12));
		exit(-1);
	}
	while (i < info->height)
	{
		if (!(info->buf[i] = (int *)malloc(sizeof(int) * (info->width))))
		{
			ft_input_texture_free(info);
			free(info->buf);
			info->buf = 0;
			ft_printf("%d : %s", 12, strerror(12));
			exit(-1);
		}
		i++;
	}
}

int		ft_buf_texture_malloc(t_info *info)
{
	int		i;

	i = -1;
	ft_buf_malloc(info);
	if (-1 == ft_malloc_zbuffer(info) || -1 == ft_texture_malloc(info, i))
		return (-1);
	ft_buf_set(info);
	return (0);
}
