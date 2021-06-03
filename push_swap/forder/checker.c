#include "../push_swap.h"

void		setup_data2(t_sd *s_data)
{
	s_data->ca = 0;
	s_data->cb = 0;
	s_data->input_d = malloc(20);
	(s_data->input_d)[19] = 0;
}

int		select_function(t_list **stack_a, t_list **stack_b, t_sd *s_data)
{
	int flag = 0;
	if(ft_strncmp(s_data->input_d, "sa", 2) == 0 && flag++)
		sa(stack_a, s_data);
	if(flag == 1)
		return 0;
	return -1;
}

int		main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;
	t_sd	s_data;

	setup_data2(&s_data);
	if(1 == argc_check_and_make_lst(&stack_a, argv, argc, &s_data))
		return 0;
	circle_lst(&stack_a, s_data.ca);
	int i = 0;
	while(1)
	{
		read(0,s_data.input_d, 20);
//		if(s_data.input_d[0] == 127)
//			write(1, "exit\n", 5);
		if(s_data.input_d[2] != '\n' || s_data.input_d[0] == '\n' || s_data.input_d[1] == '\n')
		{
			write(1, "Error\n", 6);
			exit(-1);
		}
		else if(s_data.input_d[2] == '\n')
		{
			if(-1 == select_function(&stack_a, &stack_b,&s_data))
			{
				exit(-1);
			}
		}
		int j = -1;
		while(++j < 20)
			s_data.input_d[j] = 0;
	}
	free(s_data.input_d);
	return 1;
}

