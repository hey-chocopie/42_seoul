/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascending_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <hoylee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 21:52:27 by hoylee            #+#    #+#             */
/*   Updated: 2021/06/05 21:56:30 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ascending_input(t_list **stack_a, t_sd *s_data)
{
	t_list	*tmp;
	int		i;

	i = 1;
	tmp = *stack_a;
	while (i < s_data->ca)
	{
		if (tmp->content >= tmp->next->content)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}
