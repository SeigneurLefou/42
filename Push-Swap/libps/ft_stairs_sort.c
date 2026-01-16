/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stairs_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:35:39 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/16 11:41:09 by lchamard         ###   ########.fr       */
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
	if (ft_lstsize(stacka) == 3)
	{
		if (ft_lstissup(stacka, (*stacka)->value))
			ra(stacka);
		if ((*stacka)->next->value > (*stacka)->next->next->value && (*stacka)->value < (*stacka)->next->next->value)
		 	rra(stacka);
		if ((*stacka)->value > (*stacka)->next->value)
			sa(stacka);
		if ((*stacka)->value > (*stacka)->next->next->value)
			rra(stacka);
		return (1);
	}
	if (ft_lstsize(stacka) < 6)
	{
		insert_sort_a(stacka, stackb);
		while (*stackb)
			pa(stackb, stacka);
		return (1);
	}
	return (0);
}

static void	chuncker(t_list **stacka, t_list **stackb, int chunck_nb)
{
	int	stackb_s;

	while (*stacka)
	{
		stackb_s = ft_lstsize(stackb);
		if ((*stacka) && (*stacka)->index < stackb_s)
		{
			pb(stacka, stackb);
			if ((*stacka) && (*stacka)->index > (chunck_nb + stackb_s + 1))
				rr(stacka, stackb);
			else
				rb(stackb);
		}
		else if ((*stacka) && (*stacka)->index < (chunck_nb + stackb_s))
			pb(stacka, stackb);
		else
			ra(stacka);
	}
}

void	stair_sort(t_list **stacka, t_list **stackb)
{
	int	chunck_nb;
	int	chunck_el;

	if (exception(stacka, stackb))
		return ;
	chunck_nb = 10 + (1 * (ft_lstsize(stacka) / 25)); //ft_sqrt(ft_lstsize(stacka));
	if (chunck_nb < 2)
		chunck_nb = 2;
	give_index(stacka);
	chunck_el = ft_lstsize(stacka) / chunck_nb;
	chuncker(stacka, stackb, chunck_nb);
	insert_sort_b(stacka, stackb);
}
