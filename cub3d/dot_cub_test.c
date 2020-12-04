/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_cub_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:11:44 by hoylee            #+#    #+#             */
/*   Updated: 2020/12/02 19:33:31 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_macos.h"
#include "./libft/libft.h"

int		ft_jmp(const char *s1, const char *s2, size_t n, int j)
{
	size_t				i;
	unsigned	char	*ss2;
	unsigned	char	*ss1;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	while ((ss1[i] == ss2[i] && (i < n)) && (s1[i] != 0 || s2[i] != 0))
		i++;
	if (i == n)
		return (0);
	j = 0;
	return (ss1[i] - ss2[i]);
}

int		ft_dot_check(char **text, t_info *info)
{
	if (!ft_strncmp(*text, "R ", 2))
	{
		if (-1 == ft_r(info, text))
			return (-1);
		return (1);
	}
	else if (!ft_strncmp(*text, "S ", 2))
	{
		if (-1 == ft_diretion(info, text, 2, 4))
			return (-1);
		return (1);
	}
	else if (!ft_strncmp(*text, "F ", 2))
	{
		if (-1 == ft_floor_celing_texture(info, text, 2, 7))
			return (-1);
		return (1);
	}
	else if (!ft_strncmp(*text, "C ", 2))
	{
		if (-1 == ft_floor_celing_texture(info, text, 2, 8))
			return (-1);
		return (1);
	}
	return (0);
}

int		dot_cub_test1(int *i, t_info *info, char **text, int space_i)
{
	int j;

	j = -1;
	if (((*text)[*i] == '1' || info->map_start_flag == 1) && (*text)[*i] != 0)
	{
		if (0 > ft_map(info, *text, i, space_i))
			return (-1);
		return (0);
	}
	else if (!ft_jmp(*text, "NO ", 3, ++j) || !ft_jmp(*text, "SO ", 3, ++j)
	|| !ft_jmp(*text, "WE ", 3, ++j) || !ft_jmp(*text, "EA ", 3, ++j)
	|| (!++j) || !ft_jmp(*text, "CT ", 3, ++j) || !ft_jmp(*text, "FT ", 3, ++j))
	{
		if (-1 == ft_diretion(info, text, 3, j))
			return (-1);
		return (0);
	}
	return (1);
}

int		dot_cub_test(char **text, t_info *info, int space_i)
{
	int					i;
	int					flag;

	i = 0;
	flag = dot_cub_test1(&i, info, text, space_i);
	if (flag == -1)
		return (-1);
	else if (flag == 0)
		return (0);
	if ((flag = ft_dot_check(text, info)) == -1)
		return (-1);
	if ((*text)[i] == 0 && space_i == 0)
		return (0);
	if (flag == 1)
		return (0);
	ft_printf(".cub error\n");
	return (-22);
}
