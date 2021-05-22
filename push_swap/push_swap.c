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
#include <stdio.h>
void		swap(t_list *start)
{
	int tmp;
	if(start->next != NULL)
	{
		tmp = start->content;
		start->content = (start->next)->content;
		(start->next)->content = tmp;
	}
}

void		push(t_list **give, t_list **receive)
{
	t_list *tmp;

	tmp = (*give);
	ft_lstadd_front(receive, tmp);
	tmp = (**give).next;
	(**give) = NULL;
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
	printf("%d ",(*tmp).content);
	if(i != 1)
		ft_lstadd_back(start, tmp);
	else if(i == 1)
		*start = ft_lstnew(ft_atoi(argv[i]));

	return 0;
}

int main(int argc, char **argv)
{
	t_list *stackA;
	t_list *tmp;
	int i;
	i = 1;
	if(argc < 2)
		return 0;
	while(i != argc)
	{
		if(-1 == make_stack_a(i, argv, &stackA))
			return -1;
		i++;
	}
	tmp = stackA;
//	while(tmp -> next != NULL)
//	{
//		printf("%d ", (*tmp).content);
//		(tmp) = tmp->next;
//		if (tmp -> next == NULL)
//			tmp -> next = stackA;
//	}
	return 0;
}
