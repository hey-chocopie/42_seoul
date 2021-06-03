#include "push_swap.h"

int		avr_value(t_list **stack, int range, int min_value, int stand)
{
	int i;
	int count;
	int arv;
	t_list *tmp;
	i = 0;
	count = 0;
	while(count < ((range * stand) / 3) - 1)
	{
		arv = 2147483647;
		tmp = *stack;
		i = 0;
		while(i < range)
		{
			if (min_value < (tmp)->content && arv > (tmp)->content)
				arv = tmp->content;
			tmp = tmp->next;
			i++;
		}
		min_value = arv;
		count++;
	}
	return min_value;
}

int		pivot_select(t_list **stack, int range, int *p_small)
{
	int avr;
	avr = avr_value(stack, range, min_value(stack, range), 2);
	*p_small = avr_value(stack, range, min_value(stack, range), 1);
	return avr;
}