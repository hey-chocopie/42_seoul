#include "push_swap.h"

int		stack_pre_check(t_list **stack_a, int only_pa)
{
	int i =	1;
	int max = -2147483648;
	t_list *tmp;

	tmp = *stack_a;
	if (only_pa == 0 || only_pa == 1)
		return 1;
	else
	{
		while(i < only_pa)
		{
			max = tmp->content;
			tmp = tmp->next;
			if(max > tmp->content)
				break;
			i++;
		}
		if(i == only_pa)
			return 1;
	}
	return 0;
}


int		stack_max_value(t_list **stack_a, t_list **stack_b, int *range, int pivot)
{
	int j;
	int max;
	t_list *tmp;

	j = 0;
	max = -2147483648;
	tmp = (*stack_b);
	while (j < (*range))
	{
		if (max < tmp->content)
			max = tmp->content;
		tmp = tmp->next;
		j++;
	}
	if ((*stack_b)->content == max && pivot < (*stack_b)->content && (*stack_a)->content > (*stack_b)->content)
	{
		return 1;
	}
	return 0;
}

int		lst_range_check(t_list **stack,  int range, int i,  int pivot)//int pb_max,
{
	int j;
	t_list *tmp;

	j = i;
	tmp = (*stack);
	while (j < range)
	{
		if(tmp->content <= pivot)
			break;
		tmp = tmp->next;
		j++;
	}
	if  (range != i + 1 && j == range)
		return (j - i);
	return 0;
}



int		lst2_state_check(t_list **stack, int i, int range, int p_small)
{
	int j;
	t_list *tmp;

	j = i;
	tmp = (*stack);
	while (j < range)
	{
		if(tmp->content > p_small)
			break;
		tmp = tmp->next;
		j++;
	}

	if  (range != i && j == range)
		return (j - i);
	return 0;
}

void	a_pivot_split(t_list **stack_a, t_list **stack_b, t_sd *s_data, int *remain)
{
	int i;

	i = 0;
	while (i < s_data->range)
	{
		if (0 != ((*remain) =  lst_range_check(stack_a, s_data->range, i, s_data->p_big)))
			break;
		if ((*stack_a)->content > s_data->p_big)
		{
			ra(stack_a, s_data);
			s_data->ra_c++;
		}
		else
		{
			pb(stack_a, stack_b, s_data);
			s_data->pb_c++;
			if ((*stack_b)->content >= s_data->p_small)
			{
				rb(stack_b, s_data);
				s_data->rb_c++;
			}
		}
		i++;
	}
}

void	b_pivot_split(t_list **stack_a, t_list **stack_b, t_sd *s_data, int *remain)
{
	int i;
	
	i = 0;
	while (i < s_data->range)
	{
		if (0 != (*remain =  lst2_state_check(stack_b, i, s_data->range, s_data->p_small)))
			break;
		if ((*stack_b)->content <= s_data->p_small)
		{
			rb(stack_b, s_data);
			s_data->rb_c++;
		}
		else
		{
			if(1 == stack_max_value(stack_a, stack_b, &s_data->range, s_data->p_big) && 1 ==  stack_pre_check(stack_a, s_data->pa_c - s_data->ra_c))
				s_data->pa_c = s_data->ra_c;
			else 
				s_data->pa_c++;
			pa(stack_a, stack_b, s_data);
			if((*stack_a)->content <= s_data->p_big)
			{
				ra(stack_a, s_data);
				s_data->ra_c++;
			}
		}
		i++;
	}
}