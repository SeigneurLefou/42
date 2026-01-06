/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:41:03 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/06 17:50:50 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_rotate(t_list **stack)
{
	t_list	*c_first;
	t_list	*last;

	c_first = *stack;
	last = ft_lstlast(stack);
	if (!(*stack) || ft_lstsize(stack) < 2)
		return ;
	*stack = (*stack)->next;
	c_first->next = NULL;
	last->next = c_first;
}

void	ra(t_list **stacka)
{
	ft_rotate(stacka);
}

void	rb(t_list **stackb)
{
	ft_rotate(stackb);
}

void	rr(t_list **stacka, t_list **stackb)
{
	ft_rotate(stacka);
	ft_rotate(stackb);
}
