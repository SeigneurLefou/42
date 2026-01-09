/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:35:39 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/09 11:54:51 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

static int	ft_lstisinf(t_list **stack, long min)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->index == 0 && tmp->value < min)
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
		if (tmp->index == 0 && tmp->value > max)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	give_index(t_list **stacka)
{
	int		ind;
	t_list	*tmp;

	ind = 1;
	tmp = *stacka;
	while (ind <= ft_lstsize(stacka))
	{
		while (tmp && tmp->index > 0)
			tmp = tmp->next;
		while (tmp->next && !ft_lstisinf(stacka, (tmp->value)))
		{
			tmp = tmp->next;
			while (tmp && tmp->index > 0)
				tmp = tmp->next;
		}
		tmp->index = ind;
		ind++;
		tmp = *stacka;
	}
	ft_lstshow(stacka);
}

static void	insert_sort(t_list **stacka, t_list **stackb)
{
	while (*stacka)
	{
		while (!ft_lstissup(&(*stacka), (*stacka)->value))
			ra(stacka);
		pb(stacka, stackb);
	}
}

void	stair_sort(t_list **stacka, t_list **stackb)
{
	int	chunck_nb;
	int	chunck_el;
	int	i;

	chunck_nb = 5;
	i = 1;
	if (ft_lstsize(stacka) < 5)
		return ;
	chunck_el = ft_lstsize(stacka) / chunck_nb;
	give_index(stacka);
	while (i < 5)
	{
		while (ft_lstsize(stackb) < chunck_el)
		{
			if (((i - 1) * chunck_el) < (*stacka)->index && (*stacka)->index <= (i * chunck_el))
				pb(stacka, stackb);
			rra(stacka);
		}
		ft_lstshow(stacka);
		if (1 < i)
		{
			while ((*stacka)->index != i * chunck_el)
				ra(stacka);
		}
		insert_sort(stackb, stacka);
		i++;
	}
	while (ft_lstsize(stackb) < chunck_el)
	{
		if (((i - 1) * chunck_el) < (*stacka)->index)
			pb(stacka, stackb);
		rra(stacka);
	}
	insert_sort(stackb, stacka);
}
/*
static int	ft_lstissorted(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->value < tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static t_list	**ft_presort(t_list **stacka)
{}

static int	ft_lstisinvsorted(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	insert_sort(t_list **stacka, t_list **stackb)
{
	int		len_stacka;
	long	search_int;
	t_list	*tmp;

	while (*stacka || !ft_lstissorted(stackb))
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
	while (*stackb)
		pa(stackb, stacka);
}
*/
