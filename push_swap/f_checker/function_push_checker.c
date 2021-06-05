/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_push_checker.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <hoylee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:06:23 by hoylee            #+#    #+#             */
/*   Updated: 2021/06/05 16:30:36 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		push2(t_list **give, t_list **receive)
{
	t_list *tmp;

	if (*give == 0)
		return ;
	tmp = (*give);
	if ((tmp) == tmp->next)
		(*give) = 0;
	else
		(*give) = tmp->next;
	if ((*receive) == NULL)
	{
		tmp->next = 0;
		(*receive) = tmp;
	}
	else
		ft_lstadd_front(receive, tmp);
}

void		pa2(t_list **stack_a, t_list **stack_b, t_sd *s_data)
{
	if (*stack_b == 0)
		return ;
	s_data->cb--;
	s_data->ca++;
	push2(stack_b, stack_a);
	circle_lst(stack_a, s_data->ca);
	circle_lst(stack_b, s_data->cb);
}

void		pb2(t_list **stack_a, t_list **stack_b, t_sd *s_data)
{
	if (*stack_a == 0)
		return ;
	s_data->cb++;
	s_data->ca--;
	push2(stack_a, stack_b);
	circle_lst(stack_a, s_data->ca);
	circle_lst(stack_b, s_data->cb);
}
