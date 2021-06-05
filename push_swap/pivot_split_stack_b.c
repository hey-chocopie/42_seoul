/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_split_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <hoylee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:05:25 by hoylee            #+#    #+#             */
/*   Updated: 2021/06/05 16:14:47 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stack_pre_check(t_list **stack_a, int only_pa)
{
	int		i;
	int		max;
	t_list	*tmp;

	i = 1;
	max = -2147483648;
	tmp = *stack_a;
	if (only_pa == 0 || only_pa == 1)
		return (1);
	else
	{
		while (i < only_pa)
		{
			max = tmp->content;
			tmp = tmp->next;
			if (max > tmp->content)
				break ;
			i++;
		}
		if (i == only_pa)
			return (1);
	}
	return (0);
}

int		stack_max_value(t_list **stack_a, t_list **stack_b,
										int *range, int pivot)
{
	int		j;
	int		max;
	t_list	*tmp;

	j = 0;
	max = -2147483648;
	tmp = (*stack_b);
	while (j < (*range))
	{
		if (max < tmp->content)
			max = tmp->content;
		tmp = tmp->next;
		j++;
	}
	if ((*stack_b)->content == max && pivot < (*stack_b)->content
						&& (*stack_a)->content > (*stack_b)->content)
		return (1);
	return (0);
}

int		lst2_state_check(t_list **stack, int i, int range, int p_small)
{
	int		j;
	t_list	*tmp;

	j = i;
	tmp = (*stack);
	while (j < range)
	{
		if (tmp->content > p_small)
			break ;
		tmp = tmp->next;
		j++;
	}
	if (range != i && j == range)
		return (j - i);
	return (0);
}

void	mv_stack_a(t_list **stack_a, t_list **stack_b, t_sd *s_data)
{
	pa(stack_a, stack_b, s_data);
	if ((*stack_a)->content <= s_data->p_big)
	{
		ra(stack_a, s_data);
		s_data->ra_c++;
	}
}

void	b_pivot_split(t_list **stack_a, t_list **stack_b,
									t_sd *s_data, int *remain)
{
	int i;

	i = 0;
	while (i < s_data->range)
	{
		if (0 != (*remain = lst2_state_check(stack_b,
							i, s_data->range, s_data->p_small)))
			break ;
		if ((*stack_b)->content <= s_data->p_small)
		{
			rb(stack_b, s_data);
			s_data->rb_c++;
		}
		else
		{
			if (1 == stack_max_value(stack_a, stack_b, &s_data->range,
s_data->p_big) && 1 == stack_pre_check(stack_a, s_data->pa_c - s_data->ra_c))
				s_data->pa_c = s_data->ra_c;
			else
				s_data->pa_c++;
			mv_stack_a(stack_a, stack_b, s_data);
		}
		i++;
	}
}
