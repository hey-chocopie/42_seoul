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

	if(ft_strncmp(s_data->input_d, "rra", 3) == 0 && 0 == flag++)
		rra2(stack_a, s_data);
	else if(ft_strncmp(s_data->input_d, "rrb", 3) == 0 && 0 == flag++)
		rrb2(stack_b, s_data);
	else if(ft_strncmp(s_data->input_d, "rrr", 3) == 0 && 0 == flag++)
		rrr2(stack_a, stack_b, s_data);
	else if(ft_strncmp(s_data->input_d, "sa", 2) == 0 && 0 == flag++)
		sa2(stack_a, s_data);
	else if(ft_strncmp(s_data->input_d, "sb", 2) == 0 && 0 == flag++)
		sb2(stack_b, s_data);
	else if(ft_strncmp(s_data->input_d, "ss", 2) == 0 && 0 == flag++)
		ss2(stack_a, stack_b, s_data);
	else if(ft_strncmp(s_data->input_d, "pa", 2) == 0 && 0 == flag++)
		pa2(stack_a, stack_b, s_data);
	else if(ft_strncmp(s_data->input_d, "pb", 2) == 0 && 0 == flag++)
		pb2(stack_a, stack_b, s_data);
	else if(ft_strncmp(s_data->input_d, "ra", 2) == 0 && 0 == flag++)
		ra2(stack_a, s_data);
	else if(ft_strncmp(s_data->input_d, "rb", 2) == 0 && 0 == flag++)
		rb2(stack_b, s_data);
	else if(ft_strncmp(s_data->input_d, "rr", 2) == 0 && 0 == flag++)
		rr2(stack_a, stack_b, s_data);

	if(flag == 1)
		return 0;
	return -1;
}

void	stack_check(t_list **stack_a, t_list **stack_b, t_sd *s_data)
{
	int i = 0;
	t_list *tmp;

	tmp = *stack_a;
	while(i < s_data -> ca - 1)
	{
		if(tmp->content > tmp->next->content)
		{
			write (1, "KO\n", 3);
			exit (0);
		}
	    tmp = tmp->next;
	    i++;
	}
	if(s_data->cb)
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
	t_sd	s_data;

	setup_data2(&s_data);

	int tmp = 0;
	if(1 == argc_check_and_make_lst(&stack_a, argv, argc, &s_data))
		return 0;
	circle_lst(&stack_a, s_data.ca);
	while(1)
	{	
		if((tmp = read(0, s_data.input_d, 20)) == 0)
		{
			stack_check(&stack_a, &stack_b, &s_data);
			return 0;
		}
		if(ft_strncmp(s_data.input_d, "Error",5) == 0)
		{
			write(1, "Error\n", 6);
			exit(0);
		}

		if((tmp != 3 && tmp!= 4) || s_data.input_d[0] == '\n' || s_data.input_d[1] == '\n')
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		else if(s_data.input_d[2] == '\n' || s_data.input_d[3] == '\n')
		{
			if(-1 == select_function(&stack_a, &stack_b,&s_data))
			{
				stack_d_check(stack_a, stack_b, &s_data);
				exit(0);
			}
		}
		int j = -1;
		while(++j < 20)
			s_data.input_d[j] = 0;
	}
	free(s_data.input_d);
	return 1;
}

