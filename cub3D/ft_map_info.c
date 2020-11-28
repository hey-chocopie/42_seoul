/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:41:41 by hoylee            #+#    #+#             */
/*   Updated: 2020/11/28 20:41:54 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlxfolder/mlx.h"
#include "key_macos.h"
#include "./printf/ft_printf.h"

int ft_mapcp(t_info *info)
{
    int     **mapsave;
    int     i;
    int     j;

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
    while (i < info->map.y)
    {
        j = 0;
        while (j < info->map.x)
        {
            if (info->map.tab[i][j] >= '2')
                mapsave[i][j] = 0;
            else
                mapsave[i][j] = info->map.tab[i][j] - 48;
            j++;
        }
        i++;
    }
    info->fullmap = mapsave;
    i = -1;
    j = 0;
    while (i++ < info->map.y)
    {
        free(info->map.tab[i]);
        info->map.tab[i] = 0;
    }
    free(info->map.tab);
    info->map.tab = 0;
    return (0);
}


int     ft_mapcheck(t_info *info)
{
    int     i;
    int     j;
     i = 0;
    j = 0;
     while (i < info->map.y)
    {
        j = 0;
        while (j < info->map.x)
        {
            if (info->map.tab[i][j] != '1' && i == 0)
                return (-1);
            else if (info->map.tab[i][j] != '1' && i == info->map.y - 1)
                return (-1);
            else if (info->map.tab[i][j] != '1' && j == 0)
                return (-1);
            else if (info->map.tab[i][j] != '1' && j == info->map.x - 1)
                return (-1);
            j++;
        }
        i++;
    }
    return (0);
}

int ft_map_info(t_info *info)
{
    if (-1 == ft_mapcheck(info))
    {
        ft_printf("please map check \n %d : %s", -22*(-1), strerror(-22));
        ft_input_texture_free(info);
        return (-1);
    }
    if (0 > (info->err_m =ft_mapcp(info)))
    {
        ft_printf("Cannot allocate memory \n %d : %s", info->err_m*(-1), strerror(info->err_m));
        ft_input_texture_free(info);
        return (-1);
    }
    return (0);
}
