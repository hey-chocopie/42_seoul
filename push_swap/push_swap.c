/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 18:09:05 by hoylee            #+#    #+#             */
/*   Updated: 2021/05/22 22:59:21 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

typedef struct		s_sd
{
	int		ca;
	int		cb;
	char	*s;
}					t_sd;

void	 A_to_B(t_list **stackA, t_list **stackB, t_sd *s_data, int range);
void	 B_to_A(t_list **stackA, t_list **stackB, t_sd *s_data, int range);

void		swap(t_list **start)
{
	int tmp;
	if((*start) != 0)
	{
		tmp = (*start)->content;
		(*start)->content = ((*start)->next)->content;
		((*start)->next)->content = tmp;
	}
}

void		push(t_list **give, t_list **receive)
{
	t_list *tmp;

	if(*give == 0)
		return ;
	tmp = (*give);
	if((tmp) == tmp->next)
		(*give) = 0;
	else
		(*give) = tmp->next;
	if((*receive) == NULL)
	{
		tmp->next = 0;
		(*receive) = tmp;
	}
	else
		ft_lstadd_front(receive, tmp);
}

int		 make_stack_a(int i, char **argv, t_list **start)
{
	int value;

	t_list *tmp;

	value = ft_atoi(argv[i]);
	if(value == -1)
		return -1;
	tmp = ft_lstnew(value);
	//말록한거라 start는 프리해줘야함.
	if((*start) != NULL)
		ft_lstadd_back(start, tmp);
	else if((*start) == NULL)
	{
		*start = ft_lstnew(ft_atoi(argv[i]));
	}
	return 0;
}

void		stack_d_check(t_list *stackA, t_list *stackB, t_sd *s_data)
{
	int i = 0;
	//test 0~end stack A, stackB
	printf("\nstackA : ");
//	if(stackA != 0)
//	{
		while(i <= s_data -> ca && s_data -> ca != 0)
		{
			printf("%d ", stackA->content);
			stackA = stackA->next;
			i++;
		}
//		printf("%d ", stackA->content);
//	}
	printf("\nstackB : ");
	i = 0;
//	if(stackB != 0)
//	{
		while(i <= s_data -> cb && s_data -> cb != 0)
		{
			printf("%d ", stackB->content);
			stackB = stackB->next;
			i++;
		}
//		while(stackB->next != NULL)
//		{
//			printf("%d ", stackB->content);
//			stackB = stackB->next;
//		}
//		printf("%d ", stackB->content);
//	}
}

void		setup_data(t_sd	*s_data)
{
	s_data->ca = 0;
	s_data->cb = 0;
	s_data->s = malloc(4);
	(s_data->s)[0] = 'o';
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

void		input_string(t_sd *s_data, char *tmp)
{
	int i = 0;

	while(tmp[i])
	{
		(s_data->s)[i] = tmp[i];
		i++;
	}
	tmp[i] = '\0';
	return ;
}


void		sa(t_list **stackA, t_sd *s_data)
{
	if((s_data->s)[0] == 0)
		input_string(s_data, "sa");
	else
	{
		swap(stackA);
		write(1, "sa\n", 3);
	}
}

void		sb(t_list **stackB, t_sd *s_data)
{
	if((s_data->s)[0] == 0)
		input_string(s_data, "sb");
	else
	{
		swap(stackB);
		write(1, "sb\n", 3);
	}
}

void		ss(t_list **stackA, t_list **stackB, t_sd *s_data)
{
	if((s_data->s)[0] == 0)
		input_string(s_data, "ss");
	else
	{
		swap(stackA);
		swap(stackB);
		write(1, "ss\n", 3);
	}
}

void		pa(t_list **stackA, t_list **stackB, t_sd *s_data)
{
	if(*stackB == 0)
		return ;
	if((s_data->s)[0] == 0)
		input_string(s_data, "pa");
	else
	{
		s_data -> cb--;
		s_data -> ca++;
		push(stackB, stackA);
		circle_lst(stackA, s_data -> ca);
		circle_lst(stackB, s_data -> cb);
		write(1, "pa\n", 3);
	}
}

void		pb(t_list **stackA, t_list **stackB, t_sd *s_data)
{
	if(*stackA == 0)
		return ;
	if((s_data->s)[0] == 0)
		input_string(s_data, "pb");
	else
	{
		s_data -> cb++;
		s_data -> ca--;
		push(stackA, stackB);
		circle_lst(stackA, s_data -> ca);
		circle_lst(stackB, s_data -> cb);
		write(1, "pb\n", 3);
	}
}

void	ra(t_list **stackA, t_sd *s_data)
{
	if((s_data->s)[0] == 0)
		input_string(s_data, "ra");
	else
	{
		(*stackA) = (*stackA) -> next;
		write(1, "ra\n", 3);
	}
}

void	rb(t_list **stackB, t_sd *s_data)
{	
	if((s_data->s)[0] == 0)
		input_string(s_data, "rb");
	else
	{
		(*stackB) = (*stackB) -> next;
		write(1, "rb\n", 3);
	}
}

void	rr(t_list **stackA, t_list **stackB, t_sd *s_data)
{
	if((s_data->s)[0] == 0)
		input_string(s_data, "rr");
	else
	{
		(*stackA) = (*stackA) -> next;
		(*stackB) = (*stackB) -> next;
		write(1, "rr\n", 3);
	}
	// 수정..
}

void	rra(t_list **stackA, t_sd *s_data)
{
	int i = 1;

	if((s_data->s)[0] == 0)
		input_string(s_data, "rra");
	else
	{
		while (i < s_data -> ca)
		{
			*stackA = (*stackA) -> next;
			i++;
		}
		write(1, "rra\n", 4);
	}
}

void	rrb(t_list **stackB, t_sd *s_data)
{
	int i = 1;
	if((s_data->s)[0] == 0)
		input_string(s_data, "rrb");
	else
	{
		while (i < s_data -> cb)
		{
			*stackB = (*stackB) -> next;
			i++;
		}
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_list **stackA, t_list **stackB, t_sd *s_data)
{
	int i = 1;
	if((s_data->s)[0] == 0)
		input_string(s_data, "rrr");
	else
	{
		while (i < s_data -> ca)
		{
			*stackA = (*stackA) -> next;
			i++;
		}
		i = 1;
		while (i < s_data -> cb)
		{
			*stackB = (*stackB) -> next;
			i++;
		}
		write(1, "rrr\n", 4);
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

int		select_pivot(t_list **stack, int range, int *p_small)
{
	int avr;
	avr = avr_value(stack, range, min_value(stack, range), 2);
	*p_small = avr_value(stack, range, min_value(stack, range), 1);
	return avr;
}

void		two_three_optimization(t_list **stackA, t_sd *s_data, int range)
{
	t_list *tmp;
	int flag[3] = { 0, }; 
	if (range == 2)
	{
		if((*stackA) -> next -> content < ((*stackA) -> content))
			sa(stackA, s_data);
	}
	else if (range == 3)
	{
		tmp = (*stackA);
		tmp = tmp -> next;
		if ((*stackA) -> next -> content > (*stackA) -> content)
			flag[0] = 1;
		if (tmp -> next -> content > tmp -> content)
			flag[1] = 1;
		if (tmp -> next -> content > (*stackA) -> content)
			flag[2] = 1;

		if(flag[0] == 1 && flag[1] == 1 && flag[2] == 1)//#1
			return ;
		else if(flag[0] == 1 && flag[1] == 0 && flag[2] == 1)//#2
		{
			ra(stackA, s_data);
			sa(stackA, s_data);
			rra(stackA, s_data);
		}
		else if(flag[0] == 0 && flag[1] == 1 && flag[2] == 1)
			sa(stackA, s_data);
		else if(flag[0] == 1 && flag[1] == 0 && flag[2] == 0)
		{
			if(s_data -> ca == 3)
				rra(stackA, s_data);
			else
			{
				ra(stackA, s_data);
				sa(stackA, s_data);
				rra(stackA, s_data);
				sa(stackA, s_data);
			}
		}
		else if(flag[0] == 0 && flag[1] == 1 && flag[2] == 0)
		{
			if(s_data -> ca == 3)
				ra(stackA, s_data);
			else
			{
				sa(stackA, s_data);
				ra(stackA, s_data);
				sa(stackA, s_data);
				rra(stackA, s_data);
			}
		}
		else if(flag[0] == 0 && flag[1] == 0 && flag[2] == 0)
		{
			if(s_data -> ca ==3)
			{
				sa(stackA, s_data);
				rra(stackA, s_data);
			}
			else
			{
				sa(stackA, s_data);
				ra(stackA, s_data);
				sa(stackA, s_data);
				rra(stackA, s_data);
				sa(stackA, s_data);
			}
		}
	}
}
int		lst_state_check(t_list **stack,  int range, int i,  int pivot)//int pb_max,
{
	int j;
	t_list *tmp;

	j = i;
	tmp = (*stack);
	while (j < range)
	{
		//if(tmp->content > tmp->next->content || pb_max > tmp->content)
		if(tmp->content <= pivot)
			break;
		tmp = tmp->next;
		j++;
	}
	if  (range != i + 1 && range != 1 &&  j == range)
	{
		//printf("==j-1=%d=====pivot=%d===i-%d====", j - 1, pivot, i);
		return (j - i);
	}
	return 0;
}

int		lst2_state_check(t_list **stack, int i, int range, int p_small)
{
	int j;
	t_list *tmp;

	j = i + 1;
	tmp = (*stack);
	while (j < range)
	{
		if(tmp->content <= p_small || tmp->content < tmp->next->content)
			break;
		tmp = tmp->next;
		j++;
	}
	if (tmp->next == *stack)
		return (range - j);
	return 0;
}

int		stack_max_value(t_list **stackA, t_list **stackB, int *range)
{
	int j;
	int max;
	t_list *tmp;

	j = 0;
	tmp = (*stackB);
	while (j < (*range))
	{
		tmp = tmp->next;
		if (max < tmp->content)
			max = tmp->content;
		j++;
	}
	if ((*stackB)->content == max && (*stackA)->content > (*stackB)->content)
	{
		return 1;
	}
	return 0;
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

int		good_status(t_list **stackA, int range)
{
	int i = 1;
	t_list *tmp;

	tmp = *stackA;
	while(i < range)
	{
		if(tmp->content > tmp->next->content)
			break;
		tmp = tmp->next;
		i++;
	}
	if(i == range)
		return 1;
	return 0;
}

void	 A_to_B(t_list **stackA, t_list **stackB, t_sd *s_data, int range)
{
	int i = 0;
	int pivot;
	int p_small;
	int ra_count = 0;
	int pb_count = 0;
	int rb_count = 0;
	int pb_max = 0;
	if (range == 1 || range == 0)
		return ;
	else if (range == 2 || range == 3)
	{
		two_three_optimization(stackA, s_data, range);
		return ;
	}
	else if (1 == good_status(stackA, range))
	{
		return ;
	}
	pivot = select_pivot(stackA, range, &p_small);
	int flag = 0;
	while (i < range)
	{
		if (0 != (flag =  lst_state_check(stackA, range, i, pivot)))//,pb_max
		{
			//stack_d_check(*stackA, *stackB, s_data);
			break;
		}
		if ((*stackA)->content > pivot)
		{
			if((*stackA) -> content > pb_max)
				pb_max = (*stackA) -> content;
			ra(stackA, s_data);
			ra_count++;
		}
		else
		{
			if(pb_max < (*stackA) -> content)
				pb_max = (*stackA) -> content;
			pb(stackA, stackB, s_data);
			pb_count++;
			if ((*stackB)->content >= p_small)
			{
				rb(stackB, s_data);
				rb_count++;
			}
		}
		i++;
	}
	i = 0;
//	while(i < ra_count && i <rb_count && (ra_count != s_data->ca && rb_count != s_data->cb))
//	{
//		rrr(stackA, stackB, s_data);
//		i++;
//	}
//	while(i< ra_count && ra_count != s_data->ca)
//	{
//		rra(stackA, s_data);
//		i++;
//	}
//	while(i< rb_count && rb_count != s_data->cb)
//	{
//		rrb(stackB, s_data);
//		i++;
//	}
	i = 0;

//	if (1 == location_check(s_data, ra_count, rb_count))
//	{
		//stack_d_check(*stackA, *stackB, s_data);
		while(i < rb_count && i < ra_count && (ra_count != s_data->ca && rb_count != s_data->cb))
		{
			rrr(stackA, stackB, s_data);
			i++;
		}
		while(i< ra_count && (ra_count != s_data->ca))
		{
			rra(stackA, s_data);
			i++;
		}
		while(i< rb_count && (rb_count != s_data->cb))
		{
			i++;
			rrb(stackB, s_data);
		}
//	}
//	else
//	{
//		printf("eifjowejoifjwoifjowjojowjei");
//		//stack_d_check(*stackA, *stackB, s_data);
//		while(i < s_data->cb - rb_count && i < s_data->ca - ra_count && (ra_count != s_data->ca && rb_count != s_data->cb))
//		{
//			rr(stackA, stackB, s_data);
//			i++;
//		}
//		while(i< s_data->ca - ra_count && (ra_count != s_data->ca))
//		{
//			ra(stackA, s_data);
//			i++;
//		}
//		while(i< s_data->cb - rb_count && (rb_count != s_data->cb))
//		{
//			i++;
//			rb(stackB, s_data);
//		}
//	}

	//stack_d_check(*stackA, *stackB, s_data);
	A_to_B(stackA, stackB, s_data, ra_count + flag);
	B_to_A(stackA, stackB, s_data, rb_count);
	B_to_A(stackA, stackB, s_data, pb_count - rb_count);
	return ;
}


void	 B_to_A(t_list **stackA, t_list **stackB, t_sd *s_data, int range)
{
	int i = 0;
	int pivot;
	int rb_count = 0;
	int pa_count = 0;

	int save = 0;
	int p_small = 0;
	int ra_count = 0;
	if (range == 0)
		return ;
	if (range == 1)
	{
		pa(stackA, stackB, s_data);
		return ;
	}
	if (range <4)
	{
		while(i < range)
		{
			pa(stackA, stackB, s_data);
			i++;
		}
		A_to_B(stackA, stackB, s_data, range);
		return ;
	}
	pivot = select_pivot(stackB, range, &p_small);
	while (i < range)
	{
		if (0 != (save =  lst2_state_check(stackB, i, range, p_small)))
			break;
		if(1 == stack_max_value(stackA, stackB, &range))
			pa(stackA, stackB, s_data);
		else
		{
			if ((*stackB)->content <= p_small)
			{
				rb(stackB, s_data);
				rb_count++;
			}
			else
			{			
				pa(stackA, stackB, s_data);
				pa_count++;
				if((*stackA)->content <= pivot)
				{
					ra(stackA, s_data);
					ra_count++;
				}
			}
		}
		i++;
	}


	//stack_d_check(*stackA, *stackB, s_data);
	A_to_B(stackA, stackB, s_data, pa_count - ra_count);
	i = 0;

	if (1 == location_check(s_data, ra_count, rb_count))
	{
		//stack_d_check(*stackA, *stackB, s_data);
		while(i < rb_count && i < ra_count && (ra_count != s_data->ca && rb_count != s_data->cb))
		{
			rrr(stackA, stackB, s_data);
			i++;
		}
		while(i< ra_count && (ra_count != s_data->ca))
		{
			rra(stackA, s_data);
			i++;
		}
		while(i< rb_count && (rb_count != s_data->cb))
		{
			i++;
			rrb(stackB, s_data);
		}
	}
	else
	{
		//stack_d_check(*stackA, *stackB, s_data);
		while(i < s_data->cb - rb_count && i < s_data->ca - ra_count && (ra_count != s_data->ca && rb_count != s_data->cb))
		{
			rr(stackA, stackB, s_data);
			i++;
		}
		while(i< s_data->ca - ra_count && (ra_count != s_data->ca))
		{
			ra(stackA, s_data);
			i++;
		}
		while(i< s_data->cb - rb_count && (rb_count != s_data->cb))
		{
			i++;
			rb(stackB, s_data);
		}
	}
//	while(i < rb_count && rb_count != s_data->cb)
//	{
//		rrb(stackB, s_data);
//		i++;
//	}

	//stack_d_check(*stackA, *stackB, s_data);
	A_to_B(stackA, stackB, s_data, ra_count);
	B_to_A(stackA, stackB, s_data, rb_count);
//	if (save != 0)
//		while (save-- > 0)
//			pa(stackA, stackB, s_data);
	return ;
}

void arg_string(char ***argv, int *argc, int *i)
{
	(*argv) = ft_split((*argv)[1], ' ');
	//스플릿은 free
	*i = 0;
	*argc = 0;
	while((*argv)[(*argc)])
		(*argc)++;
}
int main(int argc, char **argv)
{
	t_sd	s_data;
	t_list *stackA;
	t_list *stackB;
	int i;
	i = 1;
	setup_data(&s_data);
	if(argc < 2)
		return 0;
	if(argc == 2)
		arg_string(&argv, &argc, &i);
	while(i != argc)
	{
		s_data.ca++;
		if(-1 == make_stack_a(i, argv, &stackA))
			return -1;
		i++;
	}
	circle_lst(&stackA, s_data.ca);
	A_to_B(&stackA, &stackB, &s_data, s_data.ca);
	
	//stack_d_check(stackA, stackB, &s_data);
	return 0;
}
