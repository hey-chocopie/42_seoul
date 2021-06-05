/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <hoylee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:06:17 by hoylee            #+#    #+#             */
/*   Updated: 2021/06/05 21:54:48 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	setup_data2(t_sd *s_data, t_list **stack_a)
{
	*stack_a = 0;
	s_data->ca = 0;
	s_data->cb = 0;
	if (!(s_data->input_d = malloc(20)))
		exit(1);
	(s_data->input_d)[19] = 0;
	s_data->s = 0;
}

int		select_f(t_list **stack_a, t_list **stack_b, t_sd *s_data, int flag)
{
	if (ft_strncmp(s_data->input_d, "rra", 3) == 0 && 0 == flag++)
		rra2(stack_a, s_data);
	else if (ft_strncmp(s_data->input_d, "rrb", 3) == 0 && 0 == flag++)
		rrb2(stack_b, s_data);
	else if (ft_strncmp(s_data->input_d, "rrr", 3) == 0 && 0 == flag++)
		rrr2(stack_a, stack_b, s_data);
	else if (ft_strncmp(s_data->input_d, "sa", 2) == 0 && 0 == flag++)
		sa2(stack_a);
	else if (ft_strncmp(s_data->input_d, "sb", 2) == 0 && 0 == flag++)
		sb2(stack_b);
	else if (ft_strncmp(s_data->input_d, "ss", 2) == 0 && 0 == flag++)
		ss2(stack_a, stack_b);
	else if (ft_strncmp(s_data->input_d, "pa", 2) == 0 && 0 == flag++)
		pa2(stack_a, stack_b, s_data);
	else if (ft_strncmp(s_data->input_d, "pb", 2) == 0 && 0 == flag++)
		pb2(stack_a, stack_b, s_data);
	else if (ft_strncmp(s_data->input_d, "ra", 2) == 0 && 0 == flag++)
		ra2(stack_a);
	else if (ft_strncmp(s_data->input_d, "rb", 2) == 0 && 0 == flag++)
		rb2(stack_b);
	else if (ft_strncmp(s_data->input_d, "rr", 2) == 0 && 0 == flag++)
		rr2(stack_a, stack_b);
	if (flag == 1)
		return (0);
	return (-1);
}

void	stack_check(t_list **stack_a, t_sd *s_data)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *stack_a;
	while (i < s_data->ca - 1)
	{
		if (tmp->content > tmp->next->content)
		{
			write(1, "KO\n", 3);
			exit(0);
		}
		tmp = tmp->next;
		i++;
	}
	if (s_data->cb != 0)
	{
		write(1, "KO\n", 3);
		exit(0);
	}
	write(1, "OK\n", 3);
}

int		input_d_check_and_play(t_list **stack_a,
								t_list **stack_b, t_sd *s_data)
{
	if (ft_strncmp(s_data->input_d, "Error", 5) == 0
							&& ft_strlen(s_data->input_d) == 5)
	{
		write(2, "Error\n", 6);
		free(s_data->input_d);
		return (-1);
	}
	if ((ft_strlen(s_data->input_d) != 2 && ft_strlen(s_data->input_d) != 3))
	{
		write(2, "Error\n", 6);
		free(s_data->input_d);
		return (-1);
	}
	else
	{
		if (-1 == select_f(stack_a, stack_b, s_data, 0))
		{
			write(2, "Error\n", 6);
			free(s_data->input_d);
			return (-1);
		}
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_sd	s_data;

	setup_data2(&s_data, &stack_a);
	if (1 == argc_check_and_make_lst(&stack_a, argv, argc, &s_data))
		exit(0);
	if (s_data.ca == 1)
		exit(0);
	circle_lst(&stack_a, s_data.ca);
	while (get_next_line(0, &s_data.input_d) > 0)
	{
		s_data.argc = argc;
		if (input_d_check_and_play(&stack_a, &stack_b, &s_data) == -1)
			exit(0);
		free(s_data.input_d);
	}
	stack_check(&stack_a, &s_data);
	exit(0);
}
