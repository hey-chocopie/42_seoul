/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 18:09:05 by hoylee            #+#    #+#             */
/*   Updated: 2021/06/05 21:09:24 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		setup_data(t_list **stack_a, t_sd *s_data)
{
	*stack_a = 0;
	s_data->ca = 0;
	s_data->cb = 0;
	if (!(s_data->s = malloc(4)))
		exit(1);
	(s_data->s)[0] = 0;
}

void		info_set(t_list **stack, int range, int *remain, t_sd *s_data)
{
	s_data->ra_c = 0;
	s_data->rb_c = 0;
	s_data->pa_c = 0;
	s_data->pb_c = 0;
	*remain = 0;
	s_data->range = range;
	s_data->p_big = pivot_select(stack, range, &s_data->p_small);
}

void		a_to_b(t_list **stack_a, t_list **stack_b, t_sd *s_data, int range)
{
	int		p_sb[2];
	int		rr_ab_c[2];
	int		pb_count;
	int		remain;

	pb_count = 0;
	info_set(stack_a, range, &remain, s_data);
	if (s_data->range <= 3)
	{
		if (range == 2 || range == 3)
			two_three_optimization(stack_a, s_data, range);
		return ;
	}
	a_pivot_split(stack_a, stack_b, s_data, &remain);
	if (1 == location_check(s_data, s_data->ra_c, s_data->rb_c))
		rrr_location(stack_a, stack_b, s_data);
	else
		rr_location(stack_a, stack_b, s_data);
	pb_count = s_data->pb_c;
	data_save(s_data, rr_ab_c, p_sb, &pb_count);
	a_to_b(stack_a, stack_b, s_data, rr_ab_c[0] + remain);
	b_to_a(stack_a, stack_b, s_data, rr_ab_c[1]);
	b_to_a(stack_a, stack_b, s_data, pb_count - rr_ab_c[1]);
	return ;
}

void		b_to_a(t_list **stack_a, t_list **stack_b, t_sd *s_data, int range)
{
	int		rr_ab_c[2];
	int		pa_count;
	int		remain;
	int		p_sb[2];

	pa_count = 0;
	info_set(stack_b, range, &remain, s_data);
	if (s_data->range <= 3)
	{
		b_short_length(stack_a, stack_b, s_data, s_data->range);
		return ;
	}
	b_pivot_split(stack_a, stack_b, s_data, &remain);
	data_save(s_data, rr_ab_c, p_sb, &pa_count);
	(pa_count) = s_data->pa_c;
	a_to_b(stack_a, stack_b, s_data, s_data->pa_c - s_data->ra_c);
	data_load(s_data, rr_ab_c, p_sb, &pa_count);
	if (1 == location_check(s_data, s_data->ra_c, s_data->rb_c))
		rrr_location(stack_a, stack_b, s_data);
	else
		rr_location(stack_a, stack_b, s_data);
	rr_ab_c[1] = s_data->rb_c;
	a_to_b(stack_a, stack_b, s_data, s_data->ra_c);
	b_to_a(stack_a, stack_b, s_data, rr_ab_c[1] + remain);
	return ;
}

int			main(int argc, char **argv)
{
	t_sd	s_data;
	t_list	*stack_a;
	t_list	*stack_b;

	setup_data(&stack_a, &s_data);
	if (1 == argc_check_and_make_lst(&stack_a, argv, argc, &s_data))
		exit(0);
	circle_lst(&stack_a, s_data.ca);
	if (s_data.ca == 5)
		range_five(&stack_a, &stack_b, &s_data);
	else
		a_to_b(&stack_a, &stack_b, &s_data, s_data.ca);
	if (s_data.s[0] != 0)
	{
		write(1, s_data.s, ft_strlen(s_data.s));
		write(1, "\n", 1);
	}
	free(s_data.s);
	return (0);
}
