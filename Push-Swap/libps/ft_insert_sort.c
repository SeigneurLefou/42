/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:19:13 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/27 09:37:18 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	which_rotate(t_list *tmp, t_list **stackb, int len_stackb
		, long search_int)
{
	if (ft_lstsize(&tmp) < len_stackb / 2 + 1)
	{
		while ((long)(*stackb)->value != search_int)
			rrb(stackb);
	}
	else
	{
		while ((long)(*stackb)->value != search_int)
			rb(stackb);
	}
}

void	insert_sort_b(t_list **stacka, t_list **stackb)
{
	int		len_stackb;
	long	search_int;
	t_list	*tmp;

	while (*stackb)
	{
		len_stackb = ft_lstsize(stackb);
		tmp = *stackb;
		search_int = (long)tmp->value;
		while (tmp->next && !ft_lstissup(&tmp, search_int))
		{
			tmp = tmp->next;
			search_int = (long)tmp->value;
		}
		which_rotate(tmp, stackb, len_stackb, search_int);
		pa(stackb, stacka);
	}
}
