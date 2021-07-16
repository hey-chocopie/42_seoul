/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <seuyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:57:25 by djeon             #+#    #+#             */
/*   Updated: 2021/07/08 18:00:08 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void			check_quote_flag(char *line, int *quote_flag, int i)
{
	if ((line[i] == '\"' || line[i] == '\'') && quote_flag[0] == 0)
		quote_flag[0] = 1;
	else if ((line[i] == '\"' || line[i] == '\'') && quote_flag[0] == 1)
		quote_flag[0] = 0;
}

void			prase_set(int *i, int *start, int (*lr_quote_pipe_flag)[2])
{
	(*i) = 0;
	(*start) = 0;
	(*lr_quote_pipe_flag)[0] = 0;
	(*lr_quote_pipe_flag)[1] = 1;
}

void			put_new(t_cmd **cmd_list, t_cmd **new, t_cmd **tmp, int start)
{
	if (start == 0)
	{
		*cmd_list = (*new);
		(*tmp) = *cmd_list;
	}
	else
	{
		(*cmd_list)->next = (*new);
		*cmd_list = (*cmd_list)->next;
	}
}

void			check_pipe_flag_and_line_put_null(int i,
								char *line, int *lr_quote_pipe_flag)
{
	if (line[i] == '|')
		line[i] = '\0';
	else
		lr_quote_pipe_flag[1] = 0;
}

void			parse(t_cmd **cmd_list, char *line, char **envp)
{
	int			i;
	int			start;
	int			lr_quote_pipe_flag[2];
	t_cmd		*tmp;
	t_cmd		*new;

	prase_set(&i, &start, &lr_quote_pipe_flag);
	while (1)
	{
		check_quote_flag(line, lr_quote_pipe_flag, i);
		if (line[i] == '\0' || (line[i] == '|' && (lr_quote_pipe_flag[0]) == 0))
		{
			check_pipe_flag_and_line_put_null(i, line, lr_quote_pipe_flag);
			if ((new = ft_new(&line[start], lr_quote_pipe_flag[1], envp,
												start)) == 0)
				return ;
			put_new(cmd_list, &new, &tmp, start);
			if (lr_quote_pipe_flag[1] == 0)
				break ;
			start = i + 1;
		}
		i++;
	}
	*cmd_list = tmp;
}
