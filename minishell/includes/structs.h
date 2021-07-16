/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejpark <sejpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:39:39 by sejpark           #+#    #+#             */
/*   Updated: 2021/07/06 13:51:56 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_arg
{
	char		**argv;
	char		**envp;
}				t_arg;

typedef struct	s_nbf
{
	struct stat	*buf;
	char		*env_path;
	char		**paths;
	int			flag;
}				t_nbf;

typedef struct	s_err
{
	int				errcode;
	int				errindex;
	char			*errtoken;
}				t_err;

typedef struct	s_token
{
	char		*cmd;
	char		redir_flag;
}				t_token;

typedef struct	s_cmd
{
	t_token			*cmdline;
	int				pipe_flag;
	int				exit_flag;
	int				right_flag;
	char			quote;
	char			*path;
	char			*(redirect_filename[4]);
	struct s_err	err_manage;
	struct s_cmd	*next;
}				t_cmd;

typedef struct	s_split_flag
{
	int			cnt;
	int			begin;
	int			quote;
	int			redir;
}				t_split_flag;

#endif
