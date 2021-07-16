/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_token.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 21:43:45 by djeon             #+#    #+#             */
/*   Updated: 2021/07/06 15:43:53 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALLOC_TOKEN_H
# define FT_ALLOC_TOKEN_H
# include <stdlib.h>
# include "cmd_split.h"
# include "get_parse_size.h"
# include "ft_getenv.h"
# include "redir_chk.h"

extern int g_exit_status;

int		alloc_d_quote_cnt(char *src, char **dest, char **envp);
int		alloc_s_quote_cnt(char *src, char **dest);
t_token *ft_alloc_token(t_token *token, char **envp);
int		next_quote_or_null(char *src, char ***dest);
int		get_envkey(char *src, char **key);

#endif
