/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:03:35 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/13 16:14:56 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list **new)
{
	t_list	*tmp;

	if (!(*lst) && *new)
	{
		*lst = *new;
		return ;
	}
	if (!(*lst) || !(*new))
		return ;
	tmp = *lst;
	tmp = ft_lstlast(&tmp);
	tmp->next = *new;
}
