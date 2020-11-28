/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:08:46 by hoylee            #+#    #+#             */
/*   Updated: 2020/11/28 21:36:09 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_macos.h"
#include "./libft/libft.h"

void	ft_spr_data_save(t_info *info, int j)
{
	int a;

	a = 0;
	while (a < info->map.spr)
	{
		if (a == (info->map.spr - 1))
		{
			(info->s_save)[a].x = (info->map.y) + 0.5;
			(info->s_save)[a].y = j + 0.5;
			(info->s_save)[a].texture = 2;
		}
		else
			info->s_save[a] = info->s_tmp[a];
		a++;
	}
	if (info->map.spr > 1)
	{
		free(info->s_tmp);
		info->s_tmp = 0;
	}
}

int		ft_spr_save(t_info *info, int j)
{
	if (info->map.spr != 1)
		info->s_tmp = (info->s_save);
	if (!((info->s_save) =
		(t_sprite *)malloc(sizeof(t_sprite) * info->map.spr)))
	{
		if (info->s_tmp != 0)
		{
			free(info->s_tmp);
			info->s_tmp = 0;
		}
		info->err_m = -12;
		return (-1);
	}
	ft_spr_data_save(info, j);
	return (0);
}

int		ft_map_line_check(t_info *info, char *line, int *i, char **slab)
{
	int		j;

	j = 0;
	while (line[*i] != '\0')
	{
		if ((line[*i] == '0' || line[*i] == '1' || line[*i] == 'N')
			|| (line[*i] == 'E' || line[*i] == 'S' || line[*i] == 'W'))
			(*slab)[j++] = line[*i];
		else if (line[*i] == '2')
		{
			info->map.spr++;
			ft_spr_save(info, j);
			(*slab)[j++] = line[*i];
		}
		else if (line[*i] != ' ')
		{
			free((*slab));
			info->err_m = 22;
			return (0);
		}
		(*i)++;
	}
	return (j);
}

char	*ft_slab(t_info *info, char *line, int *i)
{
	char	*slab;
	int		slablen;
	int		j;

	if ((slablen = ft_slablen(info, line)) == -22)
	{
		info->err_m = -22;
		return (0);
	}
	if (!(slab = malloc(sizeof(char) * (slablen + 1))))
		return (0);
	if (-1 == (j = ft_map_line_check(info, line, i, &slab)))
		return (NULL);
	slab[j] = '\0';
	return (slab);
}
