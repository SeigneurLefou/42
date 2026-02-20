/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:47:16 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/13 15:06:34 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_lstisinf_ind(t_list **stack, long min)
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

int	ft_lstisinf(t_list **stack, long min)
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

int	ft_lstissup(t_list **stack, long max)
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
