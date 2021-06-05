/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <hoylee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 18:04:30 by hoylee            #+#    #+#             */
/*   Updated: 2021/06/05 18:04:32 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		stack_d_check(t_list *stack_a, t_list *stack_b, t_sd *s_data)
{
	int		i;

	i = 0;
	printf("\nstack_a : ");
	while (i <= s_data->ca && s_data->ca != 0)
	{
		printf("%d ", stack_a->content);
		stack_a = stack_a->next;
		i++;
	}
	printf("\nstack_b : ");
	i = 0;
	while (i <= s_data->cb && s_data->cb != 0)
	{
		printf("%d ", stack_b->content);
		stack_b = stack_b->next;
		i++;
	}
}
