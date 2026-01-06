/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:27:41 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/06 11:40:48 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_push(t_list *to_pop, t_list *to_push)
{
	t_list	new_node;

	new_node = ft_lstnew(to_pop->value);
	ft_lstadd_front(new_node, to_push);
	ft_lstdelone(to_pop, ft_dellst);
}

void	pa(t_list *stackb, t_list *stacka)
{
	ft_push(stackb, stacka);
}

void	pb(t_list *stacka, t_list *stackb)
{
	ft_push(stacka, stackb);
}
