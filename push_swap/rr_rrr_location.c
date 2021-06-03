#include "push_swap.h"

void	rrr_location(t_list **stack_a, t_list **stack_b, t_sd *s_data)
{
	int i;

	i = 0;
	while(i < s_data->rb_c && i < s_data->ra_c && (s_data->ra_c != s_data->ca && s_data->rb_c != s_data->cb))
	{
		rrr(stack_a, stack_b, s_data);
		i++;
	}
	while(i< s_data->ra_c && (s_data->ra_c != s_data->ca))
	{
		rra(stack_a, s_data);
		i++;
	}
	while(i< s_data->rb_c && (s_data->rb_c != s_data->cb))
	{
		i++;
		rrb(stack_b, s_data);
	}
}

void	rr_location(t_list **stack_a, t_list **stack_b, t_sd *s_data)
{
	int i;

	i = 0;
	while(i < s_data->cb - s_data->rb_c && i < s_data->ca - s_data->ra_c && (s_data->ra_c != s_data->ca && s_data->rb_c != s_data->cb))
	{
		rr(stack_a, stack_b, s_data);
		i++;
	}
	while(i< s_data->ca - s_data->ra_c && (s_data->ra_c != s_data->ca))
	{
		ra(stack_a, s_data);
		i++;
	}
	while(i< s_data->cb - s_data->rb_c && (s_data->rb_c != s_data->cb))
	{
		i++;
		rb(stack_b, s_data);
	}
}

int		location_check(t_sd *s_data, int ra_count, int rb_count)
{
	int location_rrr;
	int	location_rr;

	if(s_data->ca - ra_count > s_data->cb - rb_count)
		location_rrr = s_data->ca - ra_count;
	else
		location_rrr = s_data->cb - rb_count;
	if(ra_count > rb_count)
		location_rr = ra_count;
	else
		location_rr = rb_count;
	if(location_rrr > location_rr)
		return 1;
	else
	{
		return 0;
	}
}