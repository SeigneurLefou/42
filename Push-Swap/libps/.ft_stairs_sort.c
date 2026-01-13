/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .ft_stairs_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:35:39 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/13 16:36:24 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	body_sort(t_list **stacka, t_list **stackb,
				int chunck_nb, int chunck_el)
{
	int	i;

	i = chunck_nb - 1;
	while (i)
	{
		while (ft_lstsize(stackb) < chunck_el)
		{
			if (((i - 1) * chunck_el) <= (*stacka)->index
				&& (*stacka)->index < (i * chunck_el))
				pb(stacka, stackb);
			else
				rra(stacka);
		}
		if (i < (chunck_nb / 2 + 1))
		{
			while ((*stacka)->index != (i * chunck_el))
				ra(stacka);
		}
		if (i < chunck_nb)
		{
			while ((*stacka)->index != (i * chunck_el))
				rra(stacka);
		}
		insert_sort_b(stacka, stackb);
		i--;
	}
}

void	stair_sort(t_list **stacka, t_list **stackb)
{
	int	chunck_nb;
	int	chunck_el;
	int	last_num;

	if (exception(stacka, stackb))
		return ;
	chunck_nb = ft_sqrt(ft_lstsize(stacka)) / 2;
	if (chunck_nb < 5)
		chunck_nb = 5;
	chunck_el = ft_lstsize(stacka) / chunck_nb;
	last_num = ft_lstsize(stacka)
		- ((ft_lstsize(stacka) / chunck_nb) * chunck_nb);
	give_index(stacka);
	while (ft_lstsize(stackb) < (chunck_el + last_num))
	{
		if (((chunck_nb - 1) * chunck_el) <= (*stacka)->index)
			pb(stacka, stackb);
		rra(stacka);
	}
	insert_sort_b(stacka, stackb);
	body_sort(stacka, stackb, chunck_nb, chunck_el);
}
