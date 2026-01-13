/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:41:03 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/07 16:39:06 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **stack)
{
	t_list	*c_first;

	if (!(*stack) || ft_lstsize(stack) < 2)
		return ;
	c_first = *stack;
	*stack = (*stack)->next;
	c_first->next = NULL;
	ft_lstadd_back(stack, &c_first);
}

void	ra(t_list **stacka)
{
	ft_putendl_fd("ra", 1);
	ft_rotate(stacka);
}

void	rb(t_list **stackb)
{
	ft_putendl_fd("rb", 1);
	ft_rotate(stackb);
}

void	rr(t_list **stacka, t_list **stackb)
{
	ft_putendl_fd("rr", 1);
	ft_rotate(stacka);
	ft_rotate(stackb);
}
