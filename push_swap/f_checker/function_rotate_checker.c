/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_rotate_checker.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <hoylee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:06:36 by hoylee            #+#    #+#             */
/*   Updated: 2021/06/05 16:30:39 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra2(t_list **stack_a, t_sd *s_data)
{
	(*stack_a) = (*stack_a)->next;
}

void	rb2(t_list **stack_b, t_sd *s_data)
{
	(*stack_b) = (*stack_b)->next;
}

void	rr2(t_list **stack_a, t_list **stack_b, t_sd *s_data)
{
	(*stack_a) = (*stack_a)->next;
	(*stack_b) = (*stack_b)->next;
}
