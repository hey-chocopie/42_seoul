/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frequently_used_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <hoylee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:03:46 by hoylee            #+#    #+#             */
/*   Updated: 2021/06/05 16:30:31 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		input_string(t_sd *s_data, char *tmp)
{
	int		i;

	i = 0;
	while (tmp[i])
	{
		(s_data->s)[i] = tmp[i];
		i++;
	}
	(s_data->s)[i] = '\0';
	return ;
}

void		selector_rr(t_sd *s_data, char *tmp)
{
	if (ft_strncmp(tmp, "ra", 2) == 0 && ft_strncmp(s_data->s, "rb", 2) == 0)
	{
		write(1, "rr\n", 3);
		s_data->s[0] = 0;
	}
	else if (ft_strncmp(s_data->s, "ra", 2)
				== 0 && ft_strncmp(tmp, "rb", 2) == 0)
	{
		write(1, "rr\n", 3);
		s_data->s[0] = 0;
	}
	else
	{
		write(1, tmp, ft_strlen(tmp));
		write(1, "\n", 1);
	}
}

void		pre_value(char *s, t_sd *s_data)
{
	char	tmp[4];
	int		i;

	i = 0;
	if ((s_data->s)[0] == 0)
		input_string(s_data, s);
	else
	{
		while (s_data->s[i])
		{
			tmp[i] = s_data->s[i];
			i++;
		}
		tmp[i] = 0;
		input_string(s_data, s);
		selector_rr(s_data, tmp);
	}
}

int			min_value(t_list **stack, int depth)
{
	int		i;
	int		min_v;
	t_list	*tmp;

	tmp = (*stack);
	i = 0;
	min_v = 2147483647;
	while (i < depth)
	{
		if (tmp->content < min_v)
			min_v = tmp->content;
		tmp = tmp->next;
		i++;
	}
	return (min_v);
}

void		circle_lst(t_list **stack, int lst_depth)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (i != lst_depth)
	{
		if (i == lst_depth - 1)
		{
			tmp->next = *stack;
			break ;
		}
		else
			(tmp) = tmp->next;
		i++;
	}
}
