/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:41:03 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/06 17:59:45 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
	ft_lstadd_front(&last, stack);
}

void	rra(t_list **stacka)
{
	ft_reverse_rotate(stacka);
}

void	rrb(t_list **stackb)
{
	ft_reverse_rotate(stackb);
}

void	rrr(t_list **stacka, t_list **stackb)
{
	ft_reverse_rotate(stacka);
	ft_reverse_rotate(stackb);
}
