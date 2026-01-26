/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:06:12 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/26 13:09:33 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstmap(t_list **lst, long (*f)(long), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	long	value;

	if (!(*lst) || !f || !del)
		return (NULL);
	tmp = NULL;
	while (*lst)
	{
		value = f((*lst)->value);
		if (value)
			new = ft_lstnew(value);
		if (!new || !value)
		{
			if (value)
				del();
			ft_lstclear(&tmp, del);
			return (NULL);
		}
		ft_lstadd_back(&tmp, &new);
		*lst = (*lst)->next;
	}
	return (tmp);
}
