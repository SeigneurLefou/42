/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:41:03 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/06 11:54:26 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_reverse(t_list *stack)
{
	t_list	new_node;

	new_node = ft_lstnew(stack->value);
	ft_lstadd_back(new_node, stack);
	ft_lstdelone(stack, ft_dellst);
}

void	ra(t_list *stacka)
{
	ft_reverse(stacka);
}

void	rb(t_list *stackb)
{
	ft_reverse(stackb);
}

void	ra(t_list *stacka, t_list *stackb)
{
	ft_reverse(stacka);
	ft_reverse(stackb);
}
