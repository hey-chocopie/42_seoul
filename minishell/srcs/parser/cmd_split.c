/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <hoylee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 15:33:09 by hoylee            #+#    #+#             */
/*   Updated: 2021/07/08 18:00:12 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cmd_split.h"

static void			*ft_free(t_token *result, int len)
{
	int				i;

	i = 0;
	while (i < len)
		free(result[i++].cmd);
	return (NULL);
}

t_token				*cmd_split(char const *s, char c)
{
	int				i;
	int				cursor;
	t_token			*result;

	if (s == NULL)
		return (NULL);
	i = 0;
	cursor = 0;
	result = (t_token*)malloc(sizeof(t_token) * (ft_split_cnt(s, c) + 1));
	if (result == NULL)
		return (NULL);
	while (s[cursor])
		if (s[cursor] == c)
			cursor++;
		else
		{
			result[i].cmd = ft_alloc_word(&cursor, s, c);
			result[i].redir_flag = 0;
			if (result[i].cmd == NULL)
				return (ft_free(result, i));
			i++;
		}
	result[i].cmd = 0;
	return (result);
}
