/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 20:40:27 by hoylee            #+#    #+#             */
/*   Updated: 2020/12/03 13:03:48 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_resultaddres(t_list **lst,
		t_list *savels, t_list **new, t_list *savene)
{
	(*new)->next = NULL;
	*lst = savels;
	*new = savene;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*savels;
	t_list	*savene;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	if (!(new = (t_list *)malloc(sizeof(t_list) * 1)))
		return (0);
	new->content = (*****f)(lst->content);
	savels = lst;
	savene = new;
	while (lst->next != 0)
	{
		if (!(((*new).next) = (t_list *)malloc(sizeof(t_list) * 1)))
		{
			ft_lstclear(&savene, del);
			return (0);
		}
		new = (new->next);
		lst = lst->next;
		(new->content) = (*****f)(lst->content);
	}
	ft_resultaddres(&lst, savels, &new, savene);
	return (new);
}
