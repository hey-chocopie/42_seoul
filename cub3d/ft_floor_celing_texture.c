/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor_celing_texture.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 19:19:11 by hoylee            #+#    #+#             */
/*   Updated: 2020/12/03 15:44:58 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_macos.h"
#include "./libft/libft.h"

int		ft_rgv_int_convers(t_info *info, char *value, int *save, int *flag)
{
	if ((*flag) == 1)
		(*save) = ft_atoi(value) * 16 * 16 * 16 * 16;
	if ((*flag) == 2)
		(*save) = (*save) + ft_atoi(value) * 16 * 16;
	if ((*flag) == 3)
		(*save) = (*save) + ft_atoi(value);
	if ((*flag) > 3 || (ft_atoi(value) > 255 && ft_atoi(value) < 0))
	{
		ft_printf("check rgb input value\n");
		return (ft_tool_errorprintf(-22, info));
	}
	return (0);
}

int		ft_rgv_error(int *jump, int i, char **text, int *flag)
{
	if (i == 0 && (*text)[(*jump) + i] != 0)
	{
		ft_printf("FC input check\n%s : %d\n", strerror(22), 22);
		exit(-1);
	}
	else if (i != 0)
	{
		(*jump) = (*jump) + i;
		(*flag)++;
	}
	return (0);
}

int		ft_rgv_value(char **text, int *jump, int *flag, char *value)
{
	int		i;

	i = 0;
	while ((*text)[(*jump) + i] == ' ' || (*text)[(*jump) + i] == ',')
		(*jump)++;
	while ((*text)[(*jump) + i] >= '0' && (*text)[(*jump) + i] <= '9')
	{
		if (i >= 3)
		{
			ft_printf("FC input check\n%s : %d\n", strerror(22), 22);
			exit(-1);
		}
		value[i] = (*text)[(*jump) + i];
		i++;
	}
	if (((*text)[(*jump) + i] < '0' || (*text)[(*jump) + i] > 9) && (*text)
		[(*jump) + 1] != 0 && (*text)[(*jump) + 1] == ' '
		&& (*text)[(*jump) + 1] != ',')
	{
		ft_printf("FC input check\n%s : %d\n", strerror(22), 22);
		exit(-1);
	}
	value[i] = 0;
	return (ft_rgv_error(jump, i, text, flag));
}

int		ft_floor_celing_texture(t_info *info, char **text, int jump, int adr)
{
	int		flag;
	char	value[4];
	int		save;

	flag = 0;
	while ((*text)[jump])
	{
		ft_rgv_value(text, &jump, &flag, value);
		if (-1 == ft_rgv_int_convers(info, value, &save, &flag))
			return (-1);
	}
	if (flag > 3)
	{
		ft_printf("check rgb input value\n");
		return (ft_tool_errorprintf(-22, info));
	}
	if (adr == 7)
		info->f_texture = save;
	if (adr == 8)
		info->c_texture = save;
	return (0);
}
