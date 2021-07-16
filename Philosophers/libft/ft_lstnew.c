/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 12:49:54 by hoylee            #+#    #+#             */
/*   Updated: 2020/07/09 20:10:19 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*aa;

	if (!(aa = (t_list *)malloc(sizeof(t_list) * 1)))
		return (0);
	(*aa).content = content;
	(*aa).next = NULL;
	return (aa);
}
