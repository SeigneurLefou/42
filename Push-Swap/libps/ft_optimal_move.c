/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimal_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 10:04:30 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/15 12:03:23 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_optimal_move(t_list **stack, int min_index, int max_index)
{
	int		first_el;
	int		last_el;
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (min_index <= tmp->index && tmp->index <= max_index)
		{
			if (!first_el)
				first_el = ft_lstsize(stack) - ft_lstsize(&tmp);
			last_el = ft_lstsize(&tmp);
		}
		tmp = tmp->next;
	}
	if (first_el < last_el)
		return (1);
	else
		return (0);
}
