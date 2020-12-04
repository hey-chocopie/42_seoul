/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 22:50:52 by hoylee            #+#    #+#             */
/*   Updated: 2020/12/03 19:55:55 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_macos.h"

int		tool_fd_return(void)
{
	ft_printf("check first argument\n %d : %s\n", 22, strerror(22));
	return (-1);
}

void	ft_tool2_keysave_set(int *key_adws, char *key_save_adws, int i, char j)
{
	(*key_adws) = i;
	(*key_save_adws) = j;
}

int		ft_tool2_close(t_info *info)
{
	ft_all_free(info);
	mlx_destroy_window(info->mlx, info->win);
	exit(0);
	return (0);
}
