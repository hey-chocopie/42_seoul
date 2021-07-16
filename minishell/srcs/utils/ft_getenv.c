/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 12:36:01 by djeon             #+#    #+#             */
/*   Updated: 2021/07/08 18:01:24 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_getenv.h"

char	*get_env_value(char *key, char **envp)
{
	int i;

	i = -1;
	while (envp[++i])
	{
		if ((!ft_strncmp(key, envp[i], ft_strlen(key)))
						&& envp[i][ft_strlen(key)] == '=')
			return (envp[i] + ft_strlen(key) + 1);
	}
	return ("");
}
