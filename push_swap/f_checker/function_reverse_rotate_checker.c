#include "../push_swap.h"

void	rra2(t_list **stack_a, t_sd *s_data)
{
	int i = 1;

	while (i < s_data -> ca)
	{
		*stack_a = (*stack_a) -> next;
		i++;
	}
}

void	rrb2(t_list **stack_b, t_sd *s_data)
{
	int i = 1;

	while (i < s_data -> cb)
	{
		*stack_b = (*stack_b) -> next;
		i++;
	}
}

void	rrr2(t_list **stack_a, t_list **stack_b, t_sd *s_data)
{
	int i = 1;

	while (i < s_data -> ca)
	{
		*stack_a = (*stack_a) -> next;
		i++;
	}
	i = 1;
	while (i < s_data -> cb)
	{
		*stack_b = (*stack_b) -> next;
		i++;
	}
}
