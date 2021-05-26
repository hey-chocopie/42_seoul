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
	//printf("%d ",(*tmp).content);
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

void		sa(t_list **stackA)
{
	swap(stackA);
	write(1, "sa\n", 3);
}

void		sb(t_list **stackB)
{
	swap(stackB);
	write(1, "sb\n", 3);
}

void		ss(t_list **stackA, t_list **stackB)
{
	sa(stackA);
	sb(stackB);
	write(1, "ss\n", 3);
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
	write(1, "pa\n", 3);
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
	write(1, "pb\n", 3);
}

void	ra(t_list **stackA)
{
	(*stackA) = (*stackA) -> next;
	write(1, "ra\n", 3);
}

void	rb(t_list **stackB)
{
	(*stackB) = (*stackB) -> next;
	write(1, "rb\n", 3);
}

void	rr(t_list **stackA, t_list **stackB)
{
	ra(stackA);
	rb(stackB);
	write(1, "rr\n", 3);
	// 수정..
}

void	rra(t_list **stackA, t_sd *s_data)
{
	int i = 1;

	while (i < s_data -> ca)
	{
		*stackA = (*stackA) -> next;
		i++;
	}
	write(1, "rra\n", 4);
}

void	rrb(t_list **stackB, t_sd *s_data)
{
	int i = 1;

	while (i < s_data -> cb)
	{
		*stackB = (*stackB) -> next;
		i++;
	}
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stackA, t_list **stackB, t_sd *s_data)
{
	rra(stackA, s_data);
	rrb(stackB, s_data);
	write(1, "rrr\n", 4);
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

int		avr_value(t_list **stack, int range, int min_value)
{
	int i;
	int count;
	int arv;
	t_list *tmp;
	i = 0;
	count = 0;
	while(count < (range / 2) - 1)
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

int		select_pivot(t_list **stack, int range)
{
	//int i = 0;
	int avr;
	//t_list *tmp;

	avr = avr_value(stack, range, min_value(stack, range));
	return avr;
}

void	 A_to_B(t_list **stackA, t_list **stackB, t_sd *s_data, int range)
{
	int i = 0;
	int pivot;
	int ra_count = 0;
	int pb_count = 0;

	if (range == 1)
		return ;
	pivot = select_pivot(stackA, range);
	//스택A의 depth개의 원소 중에서 "적절한" 피봇을 선택한다

	while (i < range)
	{
		if ((*stackA)->content > pivot)
		{
			ra(stackA);
			ra_count++;
		}
		else
		{
			pb(stackA, stackB, s_data);
			pb_count++;
			//pb_호출_횟수++
		}
		i++;
	}
	i = 0;
	while(i < ra_count)
	{
		rra(stackA, s_data);
		i++;
	}
	//stack_d_check(*stackA, *stackB, s_data);
	A_to_B(stackA, stackB, s_data, ra_count);
	//stack_d_check(*stackA, *stackB, s_data);
	B_to_A(stackA, stackB, s_data, pb_count);
//	for ra_호출 횟수
//		rra #ra로 넘어간 원소들을 다시 스택 상단으로 되감기
//	A_to_B(ra_호출_횟수) #A를 최대한 가볍게 만든다
//	B_to_A(pb_호출_횟수) #A의 정렬이 끝나면 B로 넘어간 것들을 A로 올린다.
	return ;
}


void	 B_to_A(t_list **stackA, t_list **stackB, t_sd *s_data, int range)
{
	int i = 0;
	int pivot;
	int rb_count = 0;
	int pa_count = 0;

	if (range == 1)
	{
		pa(stackA, stackB, s_data);
		return ;
	}
	pivot = select_pivot(stackB, range);
	//스택B의 depth개의 원소 중에서 "적절한" 피봇을 선택한다

	while (i < range)
	{
		if ((*stackB)->content <= pivot)
		{
			rb(stackB);
			rb_count++;
		}
		else
		{
			pa(stackA, stackB, s_data);
			pa_count++;
			//pa_호출_횟수++
		}
		i++;
	}
	i = 0;
	while(i < rb_count)
	{
		rrb(stackB, s_data);
		i++;
	}
	//stack_d_check(*stackA, *stackB, s_data);
	A_to_B(stackA, stackB, s_data, pa_count);
	//stack_d_check(*stackA, *stackB, s_data);
	B_to_A(stackA, stackB, s_data, rb_count);
//	A_to_B(ra_호출_횟수) #A를 최대한 가볍게 만든다
//	B_to_A(pb_호출_횟수) #A의 정렬이 끝나면 B로 넘어간 것들을 A로 올린다.
	return ;
}


//void	def B_to_A(범위의 크기r)
//{
//	if r == 1
//		pa호출
//		return
//	스택B의 r개의 원소 중에서 "적절한" 피봇을 선택한다
//	for r개의 원소에 대해서
//		if (스택B의 top) > 피봇
//			rb명령으로 뒤로 넘긴다
//			rb_호출_횟수++
//		else
//			pa명령으로 a로 보낸다
//			pa_호출_횟수++
//	for ra_호출 횟수
//		rra #ra로 넘어간 원소들을 다시 스택 상단으로 되감기
//	A_to_B(pa_호출_횟수) #A로 넘어간 그룹
//	B_to_A(pb_호출_횟수) #B에 남은 그룹
//}

// ps 
// stack_d_check : 값들이 잘 들어가있는지 확인

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
//
//	//printf("%d", s_data.ca);
//	//------------- testzone ------------------
//	//sa(&stackA);
//	//sb(&stackB);
//	//ss(&stackA, &stackB);
//	//pa(&stackA, &stackB, &s_data);
//
//	//ra, rb 테스트
////	pb(&stackA, &stackB, &s_data);
////	pb(&stackA, &stackB, &s_data);
////	pb(&stackA, &stackB, &s_data);
////	ra(&stackA);
////	rb(&stackB);
////
////	rra(&stackA, &s_data);
////	rrb(&stackB, &s_data);
////	rrr(&stackA, &stackB, &s_data);
//	//-----------------------------------------
	A_to_B(&stackA, &stackB, &s_data, s_data.ca);
	
//	//stack_d_check(stackA, stackB, &s_data);
//	//stack_d_check(stackA, stackB, &s_data);
	return 0;
}
