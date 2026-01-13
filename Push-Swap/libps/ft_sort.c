/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:35:39 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/13 11:37:23 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	ft_sqrt(int nb)
{
	int	sqrt_nb;

	if (nb == 1)
		return (1);
	sqrt_nb = 1;
	while ((sqrt_nb * sqrt_nb) < nb)
	{
		if (sqrt_nb * sqrt_nb == nb)
			return (sqrt_nb);
		sqrt_nb++;
	}
	return (sqrt_nb);
}

static int	ft_lstisinf_ind(t_list **stack, long min)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->index == -1 && tmp->value < min)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int	ft_lstisinf(t_list **stack, long min)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->value < min)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int	ft_lstissup(t_list **stack, long max)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->value > max)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	give_index(t_list **stacka)
{
	int		ind;
	t_list	*tmp;

	ind = 0;
	tmp = *stacka;
	while (ind < ft_lstsize(stacka))
	{
		while (tmp && tmp->index > -1)
			tmp = tmp->next;
		while (tmp->next && !ft_lstisinf_ind(stacka, (tmp->value)))
		{
			tmp = tmp->next;
			while (tmp && tmp->index > -1)
				tmp = tmp->next;
		}
		tmp->index = ind;
		ind++;
		tmp = *stacka;
	}
}

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

void	stair_sort(t_list **stacka, t_list **stackb)
{
	int	chunck_nb;
	int	chunck_el;
	int	last_num;
	int	i;

	if (ft_lstsize(stacka) == 2)
	{
		if ((*stacka)->value > (*stacka)->next->value)
			sa(stacka);
		return ;
	}
	chunck_nb = ft_sqrt(ft_lstsize(stacka)) / 2;
	if (chunck_nb < 5)
		chunck_nb = 5;
	if (ft_lstsize(stacka) < 20)
	{	
		insert_sort_a(stacka, stackb);
		while (*stackb)
			pa(stackb, stacka);
		return ;
	}
	i = chunck_nb;
	chunck_el = ft_lstsize(stacka) / chunck_nb;
	last_num = ft_lstsize(stacka) - ((ft_lstsize(stacka) / chunck_nb) * chunck_nb);
	give_index(stacka);
	// First chunck
	while (ft_lstsize(stackb) < (chunck_el + last_num))
	{
		if (((i - 1) * chunck_el) <= (*stacka)->index)
			pb(stacka, stackb);
		rra(stacka);
	}
	insert_sort_b(stacka, stackb);
	i--;
	// Body chunck
	while (i)
	{
		while (ft_lstsize(stackb) < chunck_el)
		{
			if (((i - 1) * chunck_el) <= (*stacka)->index 
				&& (*stacka)->index < (i * chunck_el))
				pb(stacka, stackb);
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
