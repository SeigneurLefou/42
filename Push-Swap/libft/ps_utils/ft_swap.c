/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:41:15 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/06 17:41:14 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_swap(t_list	**stack)
{
	int	tmp;

	if (!(stack) || ft_lstsize(stack) < 2)
		return ;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value; 
	(*stack)->next->value = tmp; 
}

void	ss(t_list	**a, t_list	**b)
{
	ft_swap(a);
	ft_swap(b);
}

void	sa(t_list	**a)
{
	ft_swap(a);
}

void	sb(t_list	**b)
{
	ft_swap(b);
}
