/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:40:54 by hoylee            #+#    #+#             */
/*   Updated: 2020/12/02 19:34:16 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_macos.h"
#include "./libft/libft.h"

int		ft_slablen(t_info *info, char *line, int space_i)
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
		else if (line[i] == 'E' || line[i] == ' ')
			count++;
		i++;
	}
	count = count + space_i;
	if (info->map.x != 0 && info->map.x != count)
		return (-22);
	return (count);
}

int		ft_map(t_info *info, char *line, int *i, int space_i)
{
	char	**tmp;
	int		j;

	info->map_start_flag = 1;
	if (!(tmp = malloc(sizeof(char *) * (info->map.y + 2))))
		return (-12);
	j = -1;
	while (++j < info->map.y)
		tmp[j] = info->map.tab[j];
	if ((tmp[info->map.y] = ft_slab(info, line, i, space_i)) == NULL)
	{
		free(tmp);
		return (-12);
	}
	tmp[info->map.y + 1] = NULL;
	if (info->map.y > 0)
		free(info->map.tab);
	info->map.tab = tmp;
	info->map.y++;
	return (0);
}
