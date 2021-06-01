/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 18:09:05 by hoylee            #+#    #+#             */
/*   Updated: 2021/05/31 23:00:44 by hoylee           ###   ########.fr       */
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
	int		p_small;
	int		p_big;
	int		rb_c;
	int		ra_c;
	int		pa_c;
	int		range;
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
	int j;
	t_list *tmp;

	j = 0;
	while(argv[i][j])
	{
		if((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-')
			return -1;
		j++;
	}
	value = ft_atoi(argv[i]);
	if(value == -1 && ft_strncmp(argv[i], "-1",2) != 0 && ft_strlen(argv[i]) != 2)
		return -1;
	tmp = ft_lstnew(value);
	if((*start) != NULL)
		ft_lstadd_back(start, tmp);
	else if((*start) == NULL)
		*start = ft_lstnew(ft_atoi(argv[i]));
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
	(s_data->s)[0] = 0;
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

void		sa(t_list **stackA, t_sd *s_data)
{
	swap(stackA);
	pre_value("sa\0", s_data);
}

void		sb(t_list **stackB, t_sd *s_data)
{
	swap(stackB);
	pre_value("sb\0", s_data);
}

void		ss(t_list **stackA, t_list **stackB, t_sd *s_data)
{
	swap(stackA);
	swap(stackB);
	pre_value("ss\0", s_data);
}

void		pa(t_list **stackA, t_list **stackB, t_sd *s_data)
{
	if(*stackB == 0)
		return ;
	s_data -> cb--;
	s_data -> ca++;
	push(stackB, stackA);
	circle_lst(stackA, s_data -> ca);
	circle_lst(stackB, s_data -> cb);
	pre_value("pa\0", s_data);
}

void		pb(t_list **stackA, t_list **stackB, t_sd *s_data)
{
	if(*stackA == 0)
		return ;
	s_data -> cb++;
	s_data -> ca--;
	push(stackA, stackB);
	circle_lst(stackA, s_data -> ca);
	circle_lst(stackB, s_data -> cb);
	pre_value("pb\0", s_data);
}

void	ra(t_list **stackA, t_sd *s_data)
{
	(*stackA) = (*stackA) -> next;
	pre_value("ra\0", s_data);
}

void	rb(t_list **stackB, t_sd *s_data)
{	
	(*stackB) = (*stackB) -> next;
	pre_value("rb\0", s_data);
}

void	rr(t_list **stackA, t_list **stackB, t_sd *s_data)
{
	(*stackA) = (*stackA) -> next;
	(*stackB) = (*stackB) -> next;
	pre_value("rr\0", s_data);
}

void	rra(t_list **stackA, t_sd *s_data)
{
	int i = 1;

	while (i < s_data -> ca)
	{
		*stackA = (*stackA) -> next;
		i++;
	}
	pre_value("rra\0", s_data);
}

void	rrb(t_list **stackB, t_sd *s_data)
{
	int i = 1;

	while (i < s_data -> cb)
	{
		*stackB = (*stackB) -> next;
		i++;
	}
	pre_value("rrb\0", s_data);
}

void	rrr(t_list **stackA, t_list **stackB, t_sd *s_data)
{
	int i = 1;

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
	pre_value("rrr\0", s_data);
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

int		min_next_v(t_list **stack, int min, int depth)
{
	int i = 0;
	int min_v = 2147483647;
	t_list *tmp;

	tmp = (*stack);
	i = 0;
	while(i < depth)
	{
		if(tmp -> content < min_v && tmp->content > min)
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
 //|| tmp->content < tmp->next->content
		tmp = tmp->next;
		j++;
	}

	if  (range != i && j == range)
		return (j - i);
	return 0;
}

int		stack_max_value(t_list **stackA, t_list **stackB, int *range, int pivot)
{
	int j;
	int max;
	t_list *tmp;

	j = 0;
	max = -2147483648;
	tmp = (*stackB);
	while (j < (*range))
	{
		if (max < tmp->content)
			max = tmp->content;
		tmp = tmp->next;
		j++;
	}
	if ((*stackB)->content == max && pivot < (*stackB)->content && (*stackA)->content > (*stackB)->content)
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

//int		good_status(t_list **stackA, int range)
//{
//	int i = 1;
//	t_list *tmp;
//
//	tmp = *stackA;
//	while(i < range)
//	{
//		if(tmp->content > tmp->next->content)
//			break;
//		tmp = tmp->next;
//		i++;
//	}
//	if(i == range)
//		return 1;
//	return 0;
//}

void	 A_to_B(t_list **stackA, t_list **stackB, t_sd *s_data, int range)
{
	int i = 0;
	int pivot;
	int p_small;
	int ra_count = 0;
	int pb_count = 0;
	int rb_count = 0;
	int remain = 0;

	if (range == 1 || range == 0)
		return ;
	else if (range == 2 || range == 3)
	{
		two_three_optimization(stackA, s_data, range);
		return ;
	}
	pivot = select_pivot(stackA, range, &p_small);
	i = 0;
	while (i < range)
	{
		if (0 != (remain =  lst_range_check(stackA, range, i, pivot)))
			break;
		if ((*stackA)->content > pivot)
		{
			ra(stackA, s_data);
			ra_count++;
		}
		else
		{
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
	if (1 == location_check(s_data, ra_count, rb_count))
	{
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
			rrb(stackB, s_data);
			i++;
		}
	}
	else
	{
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
		while(i < s_data->cb - rb_count && (rb_count != s_data->cb))
		{
			i++;
			rb(stackB, s_data);
		}
	}
	A_to_B(stackA, stackB, s_data, ra_count + remain);
	B_to_A(stackA, stackB, s_data, rb_count);
	B_to_A(stackA, stackB, s_data, pb_count - rb_count);
	return ;
}

int		stack_pre_check(t_list **stackA, int only_pa)
{
	int i =	1;
	int max = -2147483648;
	t_list *tmp;

	tmp = *stackA;
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

void short_length(t_list **stackA, t_list **stackB, t_sd *s_data, int range)
{
	int i;

	i = 0;
	if (range == 0)
		return ;
	else if (range == 1)
	{
		pa(stackA, stackB, s_data);
	}
	else if (range < 4)
	{
		while(i < range)
		{
			pa(stackA, stackB, s_data);
			i++;
		}
		A_to_B(stackA, stackB, s_data, range);
	}
	return ;
}

void	pivot_sort(t_list **stackA, t_list **stackB, t_sd *s_data, int *save)
{
	int i;
	
	i = 0;
	while (i < s_data->range)
	{
		if (0 != (*save =  lst2_state_check(stackB, i, s_data->range, s_data->p_small)))
			break;
		if ((*stackB)->content <= s_data->p_small)
		{
			rb(stackB, s_data);
			s_data->rb_c++;
		}
		else
		{
			if(1 == stack_max_value(stackA, stackB, &s_data->range, s_data->p_big) && 1 ==  stack_pre_check(stackA, s_data->pa_c - s_data->ra_c))
				s_data->pa_c = s_data->ra_c;
			else 
				s_data->pa_c++;
			pa(stackA, stackB, s_data);
			if((*stackA)->content <= s_data->p_big)
			{
				ra(stackA, s_data);
				s_data->ra_c++;
			}
		}
		i++;
	}
}

void	data_save(t_sd *s_data, int *rr_ab_c, int *p_sb, int *pb_count)
{
	rr_ab_c[0] = s_data->ra_c;
	rr_ab_c[1] = s_data->rb_c;
	p_sb[0] = s_data->p_small;
	p_sb[1] = s_data->p_big;
	(*pb_count) = s_data->pa_c;
}


void	data_load(t_sd *s_data, int *rr_ab_c, int *p_sb, int *pb_count)
{
	s_data->ra_c = rr_ab_c[0];
	s_data->rb_c = rr_ab_c[1];
	s_data->p_small = p_sb[0];
	s_data->p_big = p_sb[1];
	s_data->pa_c = (*pb_count);
}

void	rrr_location(t_list **stackA, t_list **stackB, t_sd *s_data)
{
	int i;

	i = 0;
	while(i < s_data->rb_c && i < s_data->ra_c && (s_data->ra_c != s_data->ca && s_data->rb_c != s_data->cb))
	{
		rrr(stackA, stackB, s_data);
		i++;
	}
	while(i< s_data->ra_c && (s_data->ra_c != s_data->ca))
	{
		rra(stackA, s_data);
		i++;
	}
	while(i< s_data->rb_c && (s_data->rb_c != s_data->cb))
	{
		i++;
		rrb(stackB, s_data);
	}
}

void	rr_location(t_list **stackA, t_list **stackB, t_sd *s_data)
{
	int i;

	i = 0;
	while(i < s_data->cb - s_data->rb_c && i < s_data->ca - s_data->ra_c && (s_data->ra_c != s_data->ca && s_data->rb_c != s_data->cb))
	{
		rr(stackA, stackB, s_data);
		i++;
	}
	while(i< s_data->ca - s_data->ra_c && (s_data->ra_c != s_data->ca))
	{
		ra(stackA, s_data);
		i++;
	}
	while(i< s_data->cb - s_data->rb_c && (s_data->rb_c != s_data->cb))
	{
		i++;
		rb(stackB, s_data);
	}

}

void	B_to_A(t_list **stackA, t_list **stackB, t_sd *s_data, int range)
{
	int rr_ab_c[2];
	int p_sb[2];
	int pb_count = 0;
	int save = 0;

	s_data->ra_c = 0;
	s_data->rb_c = 0;
	s_data->p_big = select_pivot(stackB, range, &s_data->p_small);
	s_data->pa_c = 0;
	save = 0;
	s_data->range = range;

	if(s_data->range <= 3)
	{
		short_length(stackA, stackB, s_data, s_data->range);
		return ;
	}
	pivot_sort(stackA, stackB, s_data, &save);
	data_save(s_data, rr_ab_c, p_sb, &pb_count);
	A_to_B(stackA, stackB, s_data, s_data->pa_c - s_data->ra_c);
	data_load(s_data, rr_ab_c, p_sb, &pb_count);
	if (1 == location_check(s_data, s_data->ra_c, s_data->rb_c))
		rrr_location(stackA, stackB, s_data);
	else
		rr_location(stackA, stackB, s_data);
	rr_ab_c[1] = s_data->rb_c;
	A_to_B(stackA, stackB, s_data, s_data->ra_c);
	B_to_A(stackA, stackB, s_data, rr_ab_c[1] + save);

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

void range_five(t_list **stackA, t_list **stackB, t_sd *s_data, int range)
{
	int i;

	i = min_next_v(stackA, min_value(stackA, 5), 5);
	while(s_data->ca != 3)
	{
		if((*stackA)->content != i && (*stackA)->content == min_value(stackA, s_data->ca))
		{
			pb(stackA, stackB, s_data);
			if(s_data->ca == 3)
				sb(stackB, s_data);
		}
		else if((*stackA)->content == i)
			pb(stackA, stackB, s_data);
		else ra(stackA, s_data);
	}
	two_three_optimization(stackA, s_data, 3);
	pa(stackA, stackB, s_data);
	pa(stackA, stackB, s_data);
	return ;
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
		{
			write(1, "Error\0", 6);
			exit (-1);
		}
		i++;
	}
	if (argc == 2)
		free(argv);
	circle_lst(&stackA, s_data.ca);
	if(s_data.ca == 5)
	{
		range_five(&stackA, &stackB, &s_data, 5);
	}
	else
		A_to_B(&stackA, &stackB, &s_data, s_data.ca);
	if(s_data.s[0] != 0)
	{
		write(1, s_data.s, ft_strlen(s_data.s));
		write(1, "\n", 1);
	}
	//stack_d_check(stackA, stackB, &s_data);
	return 0;
}
