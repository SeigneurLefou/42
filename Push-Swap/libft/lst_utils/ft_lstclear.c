/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:03:31 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/26 17:15:47 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*last;

	if (!lst || !del || !*lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		last = tmp;
		tmp = tmp->next;
		del((void *)last->value);
		free(last);
	}
	*lst = NULL;
}
