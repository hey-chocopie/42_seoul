/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 20:12:56 by hoylee            #+#    #+#             */
/*   Updated: 2020/12/03 15:53:21 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_macos.h"
#include "./libft/libft.h"

void	ft_r_input_size(char *textsave, int *flag, t_info *info)
{
	textsave[99] = 0;
	if (textsave[0] != 0)
	{
		if ((*flag) == 0)
			info->width = ft_atoi(textsave);
		else if ((*flag) == 1)
			info->height = ft_atoi(textsave);
		ft_memset(textsave, 0, 100);
		(*flag)++;
	}
}

int		ft_r_err_check(char **text, int *i, int *flag, t_info *info)
{
	while ((*text)[(*i)] == ' ')
		(*i)++;
	if (((*text)[(*i)] != ' ' && (*text)[(*i)] < '0'
		&& (*text)[(*i)] > '9' && (*text)[(*i)] != 0) || (*flag) == 3)
	{
		info->err_m = -22;
		ft_printf("check R input \n");
		return (-1);
	}
	return (0);
}

void	ft_r_text_set(int *flag, int *i, char *textsave)
{
	(*flag) = 0;
	(*i) = 1;
	ft_memset(textsave, 0, 100);
}

int		ft_r_text_read(t_info *info, char **text)
{
	int		i;
	int		j;
	int		flag;
	char	textsave[100];

	ft_r_text_set(&flag, &i, textsave);
	while ((*text)[i] != 0)
	{
		j = 0;
		while ((*text)[i] >= '0' && (*text)[i] <= '9' && i < 100)
		{
			textsave[j] = (*text)[i++];
			j++;
		}
		ft_r_input_size(textsave, &flag, info);
		if (-1 == ft_r_err_check(text, &i, &flag, info))
			return (-1);
		if ((((*text)[i] < '0' || (*text)[i] > '9')
						&& (*text)[i] != 0) || i >= 100)
		{
			ft_printf("R input check\n%s : %d\n", strerror(22), 22);
			exit(-1);
		}
	}
	return (0);
}

int		ft_r(t_info *info, char **text)
{
	if (-1 == ft_r_text_read(info, text))
		return (-1);
	if ((info->winsize.size_x) < info->width)
		info->width = info->winsize.size_x;
	if ((info->winsize.size_y) < info->height)
		info->height = info->winsize.size_y;
	info->bmpwidth = info->width;
	info->bmpheigth = info->height;
	return (0);
}
