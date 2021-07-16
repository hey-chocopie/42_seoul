/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_split.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejpark <sejpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:19:26 by sejpark           #+#    #+#             */
/*   Updated: 2021/07/06 15:18:52 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_SPLIT_H
# define CMD_SPLIT_H
# include <stdlib.h>
# include "structs.h"

t_token			*cmd_split(char const *s, char c);
void			put_quote_flag(char const *s, int *quote);
int				ft_split_cnt(char const *s, const char c);
char			*ft_alloc_word(int *idx, char const *s, const char c);
#endif
