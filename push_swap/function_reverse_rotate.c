#include "push_swap.h"

void	rra(t_list **stack_a, t_sd *s_data)
{
	int i = 1;

	while (i < s_data -> ca)
	{
		*stack_a = (*stack_a) -> next;
		i++;
	}
	pre_value("rra\0", s_data);
}

void	rrb(t_list **stack_b, t_sd *s_data)
{
	int i = 1;

	while (i < s_data -> cb)
	{
		*stack_b = (*stack_b) -> next;
		i++;
	}
	pre_value("rrb\0", s_data);
}

void	rrr(t_list **stack_a, t_list **stack_b, t_sd *s_data)
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
	pre_value("rrr\0", s_data);
}