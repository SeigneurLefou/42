/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstisdouble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:20:59 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/26 10:53:54 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstisdouble(t_list **numbers)
{
	t_list	*start;
	t_list	*comp;

	start = *numbers;
	comp = (*numbers)->next;
	while (start->next)
	{
		while (comp)
		{
			if (comp->value == start->value)
				return (1);
			comp = comp->next;
		}
		start = start->next;
		comp = start->next;
	}
	return (0);
}
