/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:56:10 by djeon             #+#    #+#             */
/*   Updated: 2021/07/08 17:59:02 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void			exec_exit(t_cmd *cmd_list)
{
	long long	result;
	int			err_flag;

	err_flag = 0;
	result = ft_atoi(cmd_list->cmdline[1].cmd, &err_flag);
	if (err_flag == 1)
	{
		cmd_list->err_manage.errcode = 4;
		cmd_list->err_manage.errindex = 1;
		print_errstr(cmd_list);
		exit(-1);
	}
	exit(result % 256);
}

int				check_digit(t_cmd *cmd_list)
{
	int			i;

	i = -1;
	if (cmd_list->cmdline[1].cmd[0] == '-')
		i++;
	while (cmd_list->cmdline[1].cmd[++i] != '\0')
	{
		if (ft_isdigit(cmd_list->cmdline[1].cmd[i]) == 0)
		{
			if (cmd_list->exit_flag == 1)
			{
				cmd_list->err_manage.errcode = 4;
				cmd_list->err_manage.errindex = 1;
				print_errstr(cmd_list);
				exit(-1);
			}
			else
			{
				cmd_list->err_manage.errcode = 4;
				cmd_list->err_manage.errindex = 1;
				return (0);
			}
		}
	}
	return (1);
}

int				ft_exit(t_cmd *cmd_list)
{
	if (cmd_list->exit_flag == 1)
		printf("exit\n");
	if (cmd_list->cmdline[1].cmd != NULL)
	{
		if (check_digit(cmd_list) == 0)
			return (-1);
		if (cmd_list->cmdline[2].cmd != NULL)
		{
			cmd_list->err_manage.errcode = 2;
			return (-1);
		}
		if (cmd_list->exit_flag == 1)
			exec_exit(cmd_list);
	}
	else if (cmd_list->exit_flag == 1)
		exit(0);
	return (1);
}
