/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stairs_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:35:39 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/28 10:59:31 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	three_sort(t_list **stacka)
{
	if (ft_lstissup(stacka, (long)(*stacka)->value))
		ra(stacka);
	if ((long)(*stacka)->next->value > (long)(*stacka)->next->next->value
		&& (long)(*stacka)->value < (long)(*stacka)->next->next->value)
		rra(stacka);
	if ((long)(*stacka)->value > (long)(*stacka)->next->value)
		sa(stacka);
	if ((long)(*stacka)->value > (long)(*stacka)->next->next->value)
		rra(stacka);
}

static void	little_sort(t_list **stacka, t_list **stackb)
{
	int	surplus_stacka;

	surplus_stacka = ft_lstsize(stacka) - 3;
	give_index(stacka);
	while (ft_lstsize(stackb) < surplus_stacka)
	{
		if ((*stacka)->index < surplus_stacka)
			pb(stacka, stackb);
		else
			ra(stacka);
	}
	three_sort(stacka);
	if (*stackb && (*stackb)->index == 0 && ft_lstsize(stackb) > 1)
		sb(stackb);
	while (*stackb)
		pa(stackb, stacka);
}

static int	exception(t_list **stacka, t_list **stackb)
{
	if (ft_lstsize(stacka) == 2)
	{
		if ((long)(*stacka)->value > (long)(*stacka)->next->value)
			sa(stacka);
		return (1);
	}
	else if (ft_lstsize(stacka) < 6)
	{
		little_sort(stacka, stackb);
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

	if (exception(stacka, stackb))
		return ;
	chunck_nb = 10 + (1 * (ft_lstsize(stacka) / 25));
	if (chunck_nb < 2)
		chunck_nb = 2;
	give_index(stacka);
	chuncker(stacka, stackb, chunck_nb);
	insert_sort_b(stacka, stackb);
}
