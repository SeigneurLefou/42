/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstshow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:21:06 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/26 19:00:51 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstshow(t_list	**stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		ft_putstr_fd("val : [", 1);
		ft_putnbr_fd((long)tmp->value, 1);
		ft_putstr_fd("], index : [", 1);
		ft_putnbr_fd((long)tmp->index, 1);
		ft_putendl_fd("]", 1);
		tmp = tmp->next;
	}
}
