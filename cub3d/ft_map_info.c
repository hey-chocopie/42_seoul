/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 22:34:00 by hoylee            #+#    #+#             */
/*   Updated: 2020/12/02 20:11:44 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_macos.h"

void	ft_fullmap_save(t_info *info, int **mapsave, int *i, int *j)
{
	while ((*i) < info->map.y)
	{
		(*j) = 0;
		while ((*j) < info->map.x)
		{
			if (info->map.tab[(*i)][(*j)] >= '2')
				mapsave[(*i)][(*j)] = 0;
			else
				mapsave[(*i)][(*j)] = info->map.tab[(*i)][(*j)] - 48;
			(*j)++;
		}
		(*i)++;
	}
	info->fullmap = mapsave;
	(*i) = -1;
	(*j) = 0;
	while ((*i)++ < info->map.y)
	{
		free(info->map.tab[(*i)]);
		info->map.tab[(*i)] = 0;
	}
	free(info->map.tab);
	info->map.tab = 0;
}

int		ft_mapcp(t_info *info)
{
	int		**mapsave;
	int		i;
	int		j;

	if (!(mapsave = (int **)malloc(sizeof(int *) * (info->map.y))))
		return (-12);
	i = 0;
	while (i < info->map.y)
	{
		if (!(mapsave[i] = (int *)malloc(sizeof(int) * (info->map.x))))
		{
			free(mapsave);
			return (-12);
		}
		i++;
	}
	i = 0;
	ft_fullmap_save(info, mapsave, &i, &j);
	return (0);
}

int		ft_mapcheck(t_info *info)
{
	int		i;
	int		j;
	char	tab;

	i = -1;
	while (++i < info->map.y)
	{
		j = -1;
		while (++j < info->map.x)
		{
			tab = info->map.tab[i][j];
			if ((tab != '1' && tab != ' ') && i == 0)
				return (-1);
			else if ((tab != '1' && tab != ' ') && i == info->map.y - 1)
				return (-1);
			else if ((tab != '1' && tab != ' ') && j == 0)
				return (-1);
			else if ((tab != '1' && tab != ' ') && j == info->map.x - 1)
				return (-1);
		}
	}
	return (0);
}

int		ft_mep_zero_ceck(t_info *info)
{
	int i;
	int j;

	i = -1;
	while (++i < info->map.y)
	{
		j = -1;
		while (++j < info->map.x)
		{
			if (info->map.tab[i][j] == '0')
			{
				if (info->map.tab[i - 1][j] == ' '
	|| info->map.tab[i + 1][j] == ' '
	|| info->map.tab[i][j - 1] == ' ' || info->map.tab[i][j + 1] == ' ')
				{
					ft_printf("map error\n");
					ft_printf("%d : %s", 22, strerror(22));
					exit(-1);
				}
			}
		}
	}
	return (0);
}

int		ft_map_info(t_info *info)
{
	if (-1 == ft_mapcheck(info) || -1 == ft_mep_zero_ceck(info)
		|| -1 == ft_back_check(info))
	{
		ft_printf("please map check \n %d : %s", -22 * (-1), strerror(22));
		ft_input_texture_free(info);
		exit(-1);
	}
	if (0 > (info->err_m = ft_mapcp(info)))
	{
		ft_printf("Cannot allocate memory \n %d : %s",
				info->err_m * (-1), strerror(info->err_m));
		ft_input_texture_free(info);
		exit(-1);
	}
	return (0);
}
