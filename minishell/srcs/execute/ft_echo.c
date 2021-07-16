/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:50:12 by djeon             #+#    #+#             */
/*   Updated: 2021/07/08 17:58:51 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			n_opt_chk(char *cmd)
{
	int		i;

	i = 1;
	if (ft_strncmp("-n", cmd, 2) != 0)
		return (0);
	while (cmd[++i])
	{
		if (cmd[i] != 'n')
			return (0);
	}
	return (1);
}

int			ft_echo(t_cmd *cmd_list, int fd)
{
	int		flg;
	int		i;
	int		cnt;

	i = 1;
	flg = 0;
	cnt = 0;
	while (n_opt_chk(cmd_list->cmdline[i].cmd))
	{
		flg = 1;
		i++;
	}
	while (cmd_list->cmdline[i].cmd && cmd_list->cmdline[i].redir_flag == 0)
	{
		if (cnt != 0)
			write(fd, " ", 1);
		ft_putstr_fd(cmd_list->cmdline[i].cmd, fd);
		i++;
		cnt++;
	}
	if (flg == 0)
		write(fd, "\n", 1);
	return (1);
}
