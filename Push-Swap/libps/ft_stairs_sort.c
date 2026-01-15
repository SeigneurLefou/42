/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stairs_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:35:39 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/15 12:04:06 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	exception(t_list **stacka, t_list **stackb)
{
	if (ft_lstsize(stacka) == 2)
	{
		if ((*stacka)->value > (*stacka)->next->value)
			sa(stacka);
		return (1);
	}
	if (ft_lstsize(stacka) < 20)
	{
		insert_sort_a(stacka, stackb);
		while (*stackb)
			pa(stackb, stacka);
		return (1);
	}
	return (0);
}

static void	chuncker(t_list **stacka, t_list **stackb,
				int chunck_nb, int chunck_el)
{
	int	i;
	int	opti_move;

	i = 1;
	while (i < chunck_nb)
	{
		opti_move = ft_optimal_move(stacka,
				(i - 1) * chunck_el, i * chunck_el - 1);
		while (ft_lstsize(stackb) < (i * chunck_el))
		{
			if (((i - 1) * chunck_el) <= (*stacka)->index
				&& (*stacka)->index < (i * chunck_el))
				pb(stacka, stackb);
			else
			{
				if (opti_move)
					ra(stacka);
				else
					rra(stacka);
			}
		}
		i++;
	}
	while (*stacka)
		pb(stacka, stackb);
}

void	stair_sort(t_list **stacka, t_list **stackb)
{
	int	chunck_nb;
	int	chunck_el;

	if (exception(stacka, stackb))
		return ;
	chunck_nb = ft_sqrt(ft_lstsize(stacka)) / 2;
	if (chunck_nb < 2)
		chunck_nb = 2;
	give_index(stacka);
	chunck_el = ft_lstsize(stacka) / chunck_nb;
	chuncker(stacka, stackb, chunck_nb, chunck_el);
	insert_sort_b(stacka, stackb);
}
