/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <hoylee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:06:17 by hoylee            #+#    #+#             */
/*   Updated: 2021/06/05 16:30:36 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		setup_data2(t_sd *s_data)
{
	s_data->ca = 0;
	s_data->cb = 0;
	s_data->input_d = malloc(20);
	(s_data->input_d)[19] = 0;
	s_data->s = 0;
}

int		select_function(t_list **stack_a, t_list **stack_b, t_sd *s_data)
{
	int flag = 0;

	if (ft_strncmp(s_data->input_d, "rra", 3) == 0 && 0 == flag++)
		rra2(stack_a, s_data);
	else if (ft_strncmp(s_data->input_d, "rrb", 3) == 0 && 0 == flag++)
		rrb2(stack_b, s_data);
	else if (ft_strncmp(s_data->input_d, "rrr", 3) == 0 && 0 == flag++)
		rrr2(stack_a, stack_b, s_data);
	else if (ft_strncmp(s_data->input_d, "sa", 2) == 0 && 0 == flag++)
		sa2(stack_a, s_data);
	else if (ft_strncmp(s_data->input_d, "sb", 2) == 0 && 0 == flag++)
		sb2(stack_b, s_data);
	else if (ft_strncmp(s_data->input_d, "ss", 2) == 0 && 0 == flag++)
		ss2(stack_a, stack_b, s_data);
	else if (ft_strncmp(s_data->input_d, "pa", 2) == 0 && 0 == flag++)
		pa2(stack_a, stack_b, s_data);
	else if (ft_strncmp(s_data->input_d, "pb", 2) == 0 && 0 == flag++)
		pb2(stack_a, stack_b, s_data);
	else if (ft_strncmp(s_data->input_d, "ra", 2) == 0 && 0 == flag++)
		ra2(stack_a, s_data);
	else if (ft_strncmp(s_data->input_d, "rb", 2) == 0 && 0 == flag++)
		rb2(stack_b, s_data);
	else if (ft_strncmp(s_data->input_d, "rr", 2) == 0 && 0 == flag++)
		rr2(stack_a, stack_b, s_data);

	if (flag == 1)
		return 0;
	return -1;
}

void	stack_check(t_list **stack_a, t_list **stack_b, t_sd *s_data)
{
	int i = 0;
	t_list *tmp;

	tmp = *stack_a;
	while (i < s_data->ca - 1)
	{
		if (tmp->content > tmp->next->content)
		{
			write (1, "KO\n", 3);
			exit (0);
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

int		main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;
	t_sd s_data;
	setup_data2(&s_data);

	if (1 == argc_check_and_make_lst(&stack_a, argv, argc, &s_data))
		return 0;
	circle_lst(&stack_a, s_data.ca);
	while (get_next_line(0, &s_data.input_d) > 0)
	{
		if (ft_strncmp(s_data.input_d, "Error",5) == 0)
		{
			ft_putstr_fd("Error\n", 1);
			//printf("slkflask");
			//write(1, "Error\n", 6);
			return(0);
		}
		if (s_data.input_d != 0)
		{
			if ((ft_strlen(s_data.input_d) != 2 && ft_strlen(s_data.input_d) != 3))
			{
				ft_putstr_fd("Error\n", 1);
				//write(1, "Error\n", 6);
				return(0);
			}
			else
			{
				if (-1 == select_function(&stack_a, &stack_b,&s_data))
				{
					ft_putstr_fd("Error\n", 1);
					//write(1, "Error\n", 6);
					//stack_d_check(stack_a, stack_b, &s_data);
					return(0);
				}
			}
		}
		free(s_data.input_d);
	}
	//printf("11");
	stack_check(&stack_a, &stack_b, &s_data);
	return 1;
}

