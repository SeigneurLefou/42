/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:41:15 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/16 11:31:40 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list	**stack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (!(stack) || ft_lstsize(stack) < 2)
		return ;
	tmp1 = (*stack);
	tmp2 = (*stack)->next;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	(*stack) = tmp2;
}

void	ss(t_list	**a, t_list	**b)
{
	ft_putendl_fd("ss", 1);
	ft_swap(a);
	ft_swap(b);
}

void	sa(t_list	**a)
{
	ft_putendl_fd("sa", 1);
	ft_swap(a);
}

void	sb(t_list	**b)
{
	ft_putendl_fd("sb", 1);
	ft_swap(b);
}
