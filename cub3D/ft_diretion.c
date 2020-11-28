/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diretion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 18:27:25 by hoylee            #+#    #+#             */
/*   Updated: 2020/11/28 20:33:47 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_macos.h"
#include "./libft/libft.h"

int		texture_value(t_info *info, int adr, char *textsave)
{
	int		a;

	a = open(textsave, O_WRONLY);
	if (a == -1)
	{
		ft_printf("could not be found : %s\n", textsave);
		return (ft_tool_errorprintf(-2, info));
	}
	close(a);
	if (adr == 0)
		info->no_texture = textsave;
	else if (adr == 1)
		info->so_texture = textsave;
	else if (adr == 2)
		info->we_texture = textsave;
	else if (adr == 3)
		info->ea_texture = textsave;
	else if (adr == 4)
		info->s_texture = textsave;
	else if (adr == 5)
		info->ct_texture = textsave;
	else if (adr == 6)
		info->ft_texture = textsave;
	return (0);
}

void	ft_textsave_put(char **text, int *i, int *j, char **textsave)
{
	while ((*text)[*i] == ' ')
		(*i)++;
	while ((*text)[(*i) + (*j)] != '\n' && (*text)[(*i) + (*j)] != 0
		&& (*text)[(*i) + (*j)] != ' ')
	{
		(*textsave)[(*j)] = (*text)[(*i) + (*j)];
		(*j)++;
	}
}

int		ft_input_text_save(t_info *info, char **textsave, int jump, char **text)
{
	int		i;
	int		j;
	int		textlen;

	i = jump;
	j = 0;
	textlen = (int)strlen(*text);
	if (!((*textsave) = (char *)(malloc(sizeof(char) * (textlen - jump + 1)))))
		return (ft_tool_errorprintf(-12, info));
	if (textlen < jump)
	{
		free((*textsave));
		return (ft_tool_errorprintf(-22, info));
	}
	ft_memset((*textsave), 0, (textlen - jump + 1));
	ft_textsave_put(text, &i, &j, textsave);
	if ((*text)[i + j] != 0)
	{
		ft_printf("please check  texture adress input vlaue\n");
		free((*textsave));
		return (ft_tool_errorprintf(-22, info));
	}
	return (0);
}

int		ft_diretion(t_info *info, char **text, int jump, int adr)
{
	char	*textsave;

	textsave = 0;
	if (-1 == ft_input_text_save(info, &textsave, jump, text))
		return (-1);
	if (-1 == texture_value(info, adr, textsave))
	{
		free(textsave);
		return (ft_tool_errorprintf(-2, info));
	}
	return (0);
}
