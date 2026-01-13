/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:19:13 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/13 15:19:15 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_sort_a(t_list **stacka, t_list **stackb)
{
	int		len_stacka;
	long	search_int;
	t_list	*tmp;

	while (*stacka)
	{
		len_stacka = ft_lstsize(stacka);
		tmp = *stacka;
		search_int = tmp->value;
		while (tmp->next && !ft_lstisinf(&tmp, search_int))
		{
			tmp = tmp->next;
			search_int = tmp->value;
		}
		if (ft_lstsize(&tmp) < len_stacka / 2)
			while ((*stacka)->value != search_int)
				rra(stacka);
		else
			while ((*stacka)->value != search_int)
				ra(stacka);
		pb(stacka, stackb);
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
		search_int = tmp->value;
		while (tmp->next && !ft_lstissup(&tmp, search_int))
		{
			tmp = tmp->next;
			search_int = tmp->value;
		}
		if (ft_lstsize(&tmp) < len_stackb / 2 + 1)
			while ((*stackb)->value != search_int)
				rrb(stackb);
		else
			while ((*stackb)->value != search_int)
				rb(stackb);
		pa(stackb, stacka);
	}
}
