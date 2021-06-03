#include "push_swap.h"

void		stack_d_check(t_list *stack_a, t_list *stack_b, t_sd *s_data)
{
	int i = 0;
	//test 0~end stack A, stack_b
	printf("\nstack_a : ");
	while(i <= s_data -> ca && s_data -> ca != 0)
	{
		printf("%d ", stack_a->content);
		stack_a = stack_a->next;
		i++;
	}
	printf("\nstack_b : ");
	i = 0;
	while(i <= s_data -> cb && s_data -> cb != 0)
	{
		printf("%d ", stack_b->content);
		stack_b = stack_b->next;
		i++;
	}
}

void		input_string(t_sd *s_data, char *tmp)
{
	int i = 0;

	while(tmp[i])
	{
		(s_data->s)[i] = tmp[i];
		i++;
	}
	(s_data->s)[i] = '\0';
	return ;
}

void		pre_value(char *s, t_sd *s_data)
{
	char tmp[4];
	int i = 0;

	if((s_data->s)[0] == 0)
		input_string(s_data, s);
	else
	{
		while (s_data->s[i])
		{
			tmp[i] = s_data->s[i];
			i++;
		}
		tmp[i] = 0;
		input_string(s_data, s);

		if(ft_strncmp(tmp, "ra", 2) == 0 && ft_strncmp(s_data->s, "rb", 2) == 0)
		{
			write(1, "rr\n", 3);
			s_data->s[0] = 0;
		}
		else if(ft_strncmp(s_data->s, "ra", 2) == 0 && ft_strncmp(tmp, "rb", 2) == 0)
		{
			write(1, "rr\n", 3);
			s_data->s[0] = 0;
		}
		else
		{
			write(1, tmp, ft_strlen(tmp));
			write(1, "\n", 1);
		}
	}
}

int		min_value(t_list **stack, int depth)
{
	int i = 0;
	int min_v = 2147483647;
	t_list *tmp;

	tmp = (*stack);
	i = 0;
	while(i < depth)
	{
		if(tmp -> content < min_v)
			min_v = tmp->content;
		tmp = tmp->next;
		i++;
	}
	return min_v;
}

void		circle_lst(t_list **stack, int lst_depth)
{
	t_list	*tmp;
	int i = 0;

	tmp = *stack;
	while(i != lst_depth)
	{
		if (i == lst_depth - 1)
		{
			tmp -> next = *stack;
			break;
		}
		else
			(tmp) = tmp->next;
		i++;
	}
}
