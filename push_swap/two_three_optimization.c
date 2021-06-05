/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_three_optimization.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <hoylee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:06:05 by hoylee            #+#    #+#             */
/*   Updated: 2021/06/05 17:55:44 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		b_short_length(t_list **stack_a, t_list **stack_b,
									t_sd *s_data, int range)
{
	int i;

	i = 0;
	if (range == 0)
		return ;
	else if (range == 1)
	{
		pa(stack_a, stack_b, s_data);
	}
	else if (range < 4)
	{
		while (i < range)
		{
			pa(stack_a, stack_b, s_data);
			i++;
		}
		a_to_b(stack_a, stack_b, s_data, range);
	}
	return ;
}

void		best_choice_swap3(t_list **stack_a, t_sd *s_data, int *flag)
{
	if (flag[0] == 0 && flag[1] == 0 && flag[2] == 0)
	{
		if (s_data->ca == 3)
		{
			sa(stack_a, s_data);
			rra(stack_a, s_data);
		}
		else
		{
			sa(stack_a, s_data);
			ra(stack_a, s_data);
			sa(stack_a, s_data);
			rra(stack_a, s_data);
			sa(stack_a, s_data);
		}
	}
}

void		best_choice_swap2(t_list **stack_a, t_sd *s_data, int *flag)
{
	if (flag[0] == 0 && flag[1] == 1 && flag[2] == 0)
	{
		if (s_data->ca == 3)
			ra(stack_a, s_data);
		else
		{
			sa(stack_a, s_data);
			ra(stack_a, s_data);
			sa(stack_a, s_data);
			rra(stack_a, s_data);
		}
	}
	best_choice_swap3(stack_a, s_data, flag);
}

void		best_choice_swap(t_list **stack_a, t_sd *s_data, int *flag)
{
	if (flag[0] == 1 && flag[1] == 1 && flag[2] == 1)
		return ;
	else if (flag[0] == 1 && flag[1] == 0 && flag[2] == 1)
	{
		ra(stack_a, s_data);
		sa(stack_a, s_data);
		rra(stack_a, s_data);
	}
	else if (flag[0] == 0 && flag[1] == 1 && flag[2] == 1)
		sa(stack_a, s_data);
	else if (flag[0] == 1 && flag[1] == 0 && flag[2] == 0)
	{
		if (s_data->ca == 3)
			rra(stack_a, s_data);
		else
		{
			ra(stack_a, s_data);
			sa(stack_a, s_data);
			rra(stack_a, s_data);
			sa(stack_a, s_data);
		}
	}
	best_choice_swap2(stack_a, s_data, flag);
}

void		two_three_optimization(t_list **stack_a, t_sd *s_data, int range)
{
	t_list	*tmp;
	int		flag[3];

	flag[0] = 0;
	flag[1] = 0;
	flag[2] = 0;
	if (range == 2)
	{
		if ((*stack_a)->next->content < ((*stack_a)->content))
			sa(stack_a, s_data);
	}
	else if (range == 3)
	{
		tmp = (*stack_a);
		tmp = tmp->next;
		if ((*stack_a)->next->content > (*stack_a)->content)
			flag[0] = 1;
		if (tmp->next->content > tmp->content)
			flag[1] = 1;
		if (tmp->next->content > (*stack_a)->content)
			flag[2] = 1;
		best_choice_swap(stack_a, s_data, flag);
	}
}
