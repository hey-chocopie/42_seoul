/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:42:18 by hoylee            #+#    #+#             */
/*   Updated: 2020/12/02 23:05:20 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_macos.h"

void	ft_input_free(t_info *info)
{
	if (info->no_texture != 0)
	{
		free(info->no_texture);
		info->no_texture = 0;
	}
	if (info->so_texture != 0)
	{
		free(info->so_texture);
		info->so_texture = 0;
	}
	if (info->we_texture != 0)
	{
		free(info->we_texture);
		info->we_texture = 0;
	}
	if (info->ea_texture != 0)
	{
		free(info->ea_texture);
		info->ea_texture = 0;
	}
	if (info->s_texture != 0)
	{
		free(info->s_texture);
		info->s_texture = 0;
	}
}

void	ft_input_texture_free(t_info *info)
{
	ft_input_free(info);
	if (info->ft_texture != 0)
	{
		free(info->ft_texture);
		info->ft_texture = 0;
	}
	if (info->ct_texture != 0)
	{
		free(info->ct_texture);
		info->ct_texture = 0;
	}
	if (info->s_tmp != 0)
	{
		free(info->s_tmp);
		info->s_tmp = 0;
	}
}

void	ft_tool_mem_free(t_info *info, int flag)
{
	int		i;

	i = -1;
	while (++i < info->height)
	{
		if (info->buf != 0)
			if (info->buf[i] != 0)
				free(info->buf[i]);
	}
	if (info->buf != 0)
		free(info->buf);
	ft_input_texture_free(info);
	if (info->zbuffer != 0)
		free(info->zbuffer);
	if (info->texture != 0)
		free(info->texture);
	if (flag == 1)
		ft_printf("%s : %d", strerror(12), 12);
}

void	ft_all_free(t_info *info)
{
	int		i;

	i = -1;
	while (++i < info->texturecount)
		if (info->texture != 0)
			free(info->texture[i]);
	ft_tool_mem_free(info, 0);
}

int		ft_tool_errorprintf(int a, t_info *info)
{
	info->err_m = -a;
	return (-1);
}
