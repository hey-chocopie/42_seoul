/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_split_stack_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <hoylee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 17:36:18 by hoylee            #+#    #+#             */
/*   Updated: 2021/06/05 17:36:44 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		lst_range_check(t_list **stack, int range,
									int i, int pivot)
{
	int		j;
	t_list	*tmp;

	j = i;
	tmp = (*stack);
	while (j < range)
	{
		if (tmp->content <= pivot)
			break ;
		tmp = tmp->next;
		j++;
	}
	if (range != i + 1 && j == range)
		return (j - i);
	return (0);
}

void	a_pivot_split(t_list **stack_a, t_list **stack_b,
								t_sd *s_data, int *remain)
{
	int i;

	i = 0;
	while (i < s_data->range)
	{
		if (0 != ((*remain) = lst_range_check(stack_a,
						s_data->range, i, s_data->p_big)))
			break ;
		if ((*stack_a)->content > s_data->p_big)
		{
			ra(stack_a, s_data);
			s_data->ra_c++;
		}
		else
		{
			pb(stack_a, stack_b, s_data);
			s_data->pb_c++;
			if ((*stack_b)->content >= s_data->p_small)
			{
				rb(stack_b, s_data);
				s_data->rb_c++;
			}
		}
		i++;
	}
}
