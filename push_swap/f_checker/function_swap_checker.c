/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_swap_checker.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <hoylee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:06:43 by hoylee            #+#    #+#             */
/*   Updated: 2021/06/05 16:14:51 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		swap2(t_list **start)
{
	int tmp;
	if ((*start) != 0)
	{
		tmp = (*start)->content;
		(*start)->content = ((*start)->next)->content;
		((*start)->next)->content = tmp;
	}
}

void		sa2(t_list **stack_a, t_sd *s_data)
{
	swap2(stack_a);
}

void		sb2(t_list **stack_b, t_sd *s_data)
{
	swap2(stack_b);
}

void		ss2(t_list **stack_a, t_list **stack_b, t_sd *s_data)
{
	swap2(stack_a);
	swap2(stack_b);
}
