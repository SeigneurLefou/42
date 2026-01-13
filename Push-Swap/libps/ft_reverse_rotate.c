/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:41:03 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/07 16:39:47 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*lst;

	if (!(*stack) || ft_lstsize(stack) < 2)
		return ;
	last = ft_lstlast(stack);
	lst = *stack;
	while (lst->next->next)
		lst = lst->next;
	lst->next = NULL;
	ft_lstadd_front(stack, &last);
}

void	rra(t_list **stacka)
{
	ft_putendl_fd("rra", 1);
	ft_reverse_rotate(stacka);
}

void	rrb(t_list **stackb)
{
	ft_putendl_fd("rrb", 1);
	ft_reverse_rotate(stackb);
}

void	rrr(t_list **stacka, t_list **stackb)
{
	ft_putendl_fd("rrr", 1);
	ft_reverse_rotate(stacka);
	ft_reverse_rotate(stackb);
}
