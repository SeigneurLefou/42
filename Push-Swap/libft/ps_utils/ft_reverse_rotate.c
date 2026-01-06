/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:41:03 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/06 12:28:11 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_reverse_rotate(t_list *stack)
{
	t_list	new_node;

	new_node = ft_lstlast(stack);
	ft_lstadd_front(new_node, stack);
	ft_lstdelone(ft_lstlast(stack), ft_dellst);
}

void	ra(t_list *stacka)
{
	ft_reverse_rotate(stacka);
}

void	rb(t_list *stackb)
{
	ft_reverse_rotate(stackb);
}

void	ra(t_list *stacka, t_list *stackb)
{
	ft_reverse_rotate(stacka);
	ft_reverse_rotate(stackb);
}
