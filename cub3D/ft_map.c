/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:40:54 by hoylee            #+#    #+#             */
/*   Updated: 2020/11/28 21:01:56 by hoylee           ###   ########.fr       */
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
