/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:27:41 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/09 14:53:15 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ft_push(t_list **to_pop, t_list **to_push)
{
	t_list	*new_node;

	if (!to_push && to_pop)
	{
		*to_push = ft_lstnew((*to_pop)->value);
		*to_pop = (*to_pop)->next;
		return ;
	}
	if (!to_pop)
		return ;
	new_node = ft_lstnew((*to_pop)->value);
	new_node->index = (*to_pop)->index;
	ft_lstadd_front(to_push, &new_node);
	*to_pop = (*to_pop)->next;
}

void	pa(t_list **stackb, t_list **stacka)
{
	ft_putendl_fd("pa", 1);
	ft_push(stackb, stacka);
}

void	pb(t_list **stacka, t_list **stackb)
{
	ft_putendl_fd("pb", 1);
	ft_push(stacka, stackb);
}
