/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:40:54 by hoylee            #+#    #+#             */
/*   Updated: 2020/11/26 11:51:07 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "key_macos.h"
#include "./libft/libft.h"

int		ft_slablen(t_info *info, char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == '2')
			count++;
		else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W')
			count++;
		else if (line[i] == 'E')
			count++;
		i++;
	}
	if (info->map.x != 0 && info->map.x != count)
		return (-22);
	return (count);
}

int		ft_spr_save(t_info *info, int j)
{
	if(info->map.spr != 1)
		info->s_tmp =(info->s_save);
	if(!((info->s_save) = (t_sprite *)malloc(sizeof(t_sprite) * info->map.spr)))
	{
		if(info->s_tmp != 0)
		{
			free(info->s_tmp);
			info->s_tmp = 0;
		}
		info->err_m = -12;
		return(-1);
	}
	int a;
	a = 0;
	printf("\n%d\n", info->map.y);
	while(a < info->map.spr)
	{
		if(a == (info->map.spr - 1))
		{
			(info->s_save)[a].x = (info->map.y)+0.5;
			(info->s_save)[a].y = j+0.5;
			(info->s_save)[a].texture = 2;
		}
		else
		{
			(info->s_save)[a].x = (info->s_tmp)[a].x;
			(info->s_save)[a].y = (info->s_tmp)[a].y;
			(info->s_save)[a].texture = (info->s_tmp)[a].texture;
		}
		a++;
	}
	if(info->map.spr > 1)
	{
		free(info->s_tmp);
		info ->s_tmp = 0;
	}
	return(0);
}

char	*ft_slab(t_info *info, char *line, int *i)
{
	char	*slab;
	int		j;
	int		slablen;

	if((slablen = ft_slablen(info, line)) == -22)
	{
		info->err_m = -22;
		return (0);
	}
	if (!(slab = malloc(sizeof(char) * (slablen + 1))))
		return (0);
	j = 0;
	while (line[*i] != '\0')
	{
		if ((line[*i] == '0' || line[*i] == '1' || line[*i] == 'N')
			|| (line[*i] == 'E' || line[*i] == 'S' || line[*i] == 'W'))
			slab[j++] = line[*i];
		else if (line[*i] == '2')
		{
			info->map.spr++;
			ft_spr_save(info, j);
			slab[j++] = line[*i];
		}
		else if (line[*i] != ' ')
		{
			free(slab);
			info->err_m = 22;
			return (NULL);
		}
		(*i)++;
	}
	slab[j] = '\0';
	return (slab);
}

int		ft_map(t_info *info, char *line, int *i)
{
	char	**tmp;
	int		j;

	info->err_m = 1;
	if (!(tmp = malloc(sizeof(char *) * (info->map.y + 2))))
		return (-12);
	j = -1;
	while (++j < info->map.y)
		tmp[j] = info->map.tab[j];
	if ((tmp[info->map.y] = ft_slab(info, line, i)) == NULL)
	{
		free(tmp);
		return (-12);
	}
	tmp[info->map.y + 1] = NULL;
	if (info->map.y > 0)
		free(info->map.tab);
	info->map.tab = tmp;
	info->map.y++;
	if ((info->map.x = ft_slablen(info, line)) < 0)
		return (-22);
	return (0);
}
