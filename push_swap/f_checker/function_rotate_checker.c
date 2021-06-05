#include "../push_swap.h"

void	ra2(t_list **stack_a, t_sd *s_data)
{
	(*stack_a) = (*stack_a) -> next;
}

void	rb2(t_list **stack_b, t_sd *s_data)
{	
	(*stack_b) = (*stack_b) -> next;
}

void	rr2(t_list **stack_a, t_list **stack_b, t_sd *s_data)
{
	(*stack_a) = (*stack_a) -> next;
	(*stack_b) = (*stack_b) -> next;
}
