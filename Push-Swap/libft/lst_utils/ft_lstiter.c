/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:04:01 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/26 19:00:19 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstiter(t_list **lst, void (*f)(void *))
{
	t_list	*tmp;

	if (!(*lst) || !f)
		return ;
	tmp = *lst;
	while (tmp)
	{
		f((void *)tmp->value);
		tmp = tmp->next;
	}
}
