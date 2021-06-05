/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <hoylee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:04:18 by hoylee            #+#    #+#             */
/*   Updated: 2021/06/05 16:30:32 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a, t_sd *s_data)
{
	(*stack_a) = (*stack_a)->next;
	pre_value("ra\0", s_data);
}

void	rb(t_list **stack_b, t_sd *s_data)
{
	(*stack_b) = (*stack_b)->next;
	pre_value("rb\0", s_data);
}

void	rr(t_list **stack_a, t_list **stack_b, t_sd *s_data)
{
	(*stack_a) = (*stack_a)->next;
	(*stack_b) = (*stack_b)->next;
	pre_value("rr\0", s_data);
}
