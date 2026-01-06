/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:27:41 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/06 17:47:13 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_push(t_list **to_pop, t_list **to_push)
{
	t_list	*new_node;

	if (!(to_pop) || !(to_push) || ft_lstsize(to_pop) < 1)
		return ;
	new_node = ft_lstnew((*to_pop)->value);
	ft_lstadd_front(&new_node, to_push);
	*to_pop = (*to_pop)->next;
}

void	pa(t_list **stackb, t_list **stacka)
{
	ft_push(stackb, stacka);
}

void	pb(t_list **stacka, t_list **stackb)
{
	ft_push(stacka, stackb);
}
