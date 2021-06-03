/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 18:09:05 by hoylee            #+#    #+#             */
/*   Updated: 2021/06/03 22:13:38 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	 A_to_B(t_list **stack_a, t_list **stack_b, t_sd *s_data, int range);
//void	 B_to_A(t_list **stack_a, t_list **stack_b, t_sd *s_data, int range);
//


<<<<<<< HEAD
void		setup_data(t_sd	*s_data)
=======
void		setup_data(t_list **stack_a, t_sd	*s_data)
>>>>>>> f5c52a659c20cce6591b58eca151b22b87e3a969
{
	*stack_a = 0;
	s_data->ca = 0;
	s_data->cb = 0;
	s_data->s = malloc(4);
	(s_data->s)[0] = 0;
}



void	info_set(t_list **stack, int range, int *remain, t_sd *s_data)
{
	s_data->ra_c = 0;
	s_data->rb_c = 0;
	s_data->pa_c = 0;
	s_data->pb_c = 0;
	*remain = 0;
	s_data->range = range;
	s_data->p_big = pivot_select(stack, range, &s_data->p_small);
}


void	 A_to_B(t_list **stack_a, t_list **stack_b, t_sd *s_data, int range)
{
	int i = 0;
	int p_sb[2];
	int rr_ab_c[2];
	int pb_count = 0;
	int remain = 0;

	info_set(stack_a, range, &remain, s_data);
	if(s_data->range <= 3)
	{
		if(range == 2 || range == 3)
			two_three_optimization(stack_a, s_data, range);
		return ;
	}
	a_pivot_split(stack_a, stack_b, s_data, &remain);
	i = 0;
	if (1 == location_check(s_data, s_data->ra_c, s_data->rb_c))
		rrr_location(stack_a, stack_b, s_data);
	else
		rr_location(stack_a, stack_b, s_data);
	pb_count = s_data->pb_c;
	data_save(s_data, rr_ab_c, p_sb, &pb_count);
	A_to_B(stack_a, stack_b, s_data, rr_ab_c[0] + remain);
	B_to_A(stack_a, stack_b, s_data, rr_ab_c[1]);
	B_to_A(stack_a, stack_b, s_data, pb_count - rr_ab_c[1]);
	return ;
}

void	B_to_A(t_list **stack_a, t_list **stack_b, t_sd *s_data, int range)
{
	int rr_ab_c[2];
	int pa_count = 0;
	int remain = 0;
	int p_sb[2];

	info_set(stack_b, range, &remain, s_data);
	if(s_data->range <= 3)
	{
		b_short_length(stack_a, stack_b, s_data, s_data->range);
		return ;
	}
	b_pivot_split(stack_a, stack_b, s_data, &remain);
	data_save(s_data, rr_ab_c, p_sb, &pa_count);
	(pa_count) = s_data->pa_c;
	A_to_B(stack_a, stack_b, s_data, s_data->pa_c - s_data->ra_c);
	data_load(s_data, rr_ab_c, p_sb, &pa_count);
	if (1 == location_check(s_data, s_data->ra_c, s_data->rb_c))
		rrr_location(stack_a, stack_b, s_data);
	else
		rr_location(stack_a, stack_b, s_data);
	rr_ab_c[1] = s_data->rb_c;
	A_to_B(stack_a, stack_b, s_data, s_data->ra_c);
	B_to_A(stack_a, stack_b, s_data, rr_ab_c[1] + remain);
	return ;
}

<<<<<<< HEAD
//int main(int argc, char **argv)
//{
//	t_sd	s_data;
//	t_list *stack_a;
//	t_list *stack_b;
//	int i;
//
//	setup_data(&s_data);
//	if(1 == argc_check_and_make_lst(&stack_a, argv, argc, &s_data))
//		return 0;
//	circle_lst(&stack_a, s_data.ca);
//	if(s_data.ca == 5)
//		range_five(&stack_a, &stack_b, &s_data, 5);
//	else
//		A_to_B(&stack_a, &stack_b, &s_data, s_data.ca);
//	if(s_data.s[0] != 0)
//	{
//		write(1, s_data.s, ft_strlen(s_data.s));
//		write(1, "\n", 1);
//	}
//	free(s_data.s);
//	//stack_d_check(stack_a, stack_b, &s_data);
//	return 0;
//}
=======
int main(int argc, char **argv)
{
	t_sd	s_data;
	t_list *stack_a;
	t_list *stack_b;
//	int i;

	setup_data(&stack_a, &s_data);
	if(1 == argc_check_and_make_lst(&stack_a, argv, argc, &s_data))
		return 0;
	circle_lst(&stack_a, s_data.ca);
	if(s_data.ca == 5)
		range_five(&stack_a, &stack_b, &s_data, 5);
	else
		A_to_B(&stack_a, &stack_b, &s_data, s_data.ca);
	if(s_data.s[0] != 0)
	{
		write(1, s_data.s, ft_strlen(s_data.s));
		write(1, "\n", 1);
	}
	free(s_data.s);
	//stack_d_check(stack_a, stack_b, &s_data);
	return 0;
}
>>>>>>> f5c52a659c20cce6591b58eca151b22b87e3a969
