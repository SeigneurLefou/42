/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:18:12 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/26 19:13:01 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	give_index(t_list **stacka)
{
	int		ind;
	t_list	*tmp;

	ind = 0;
	tmp = *stacka;
	while (ind < ft_lstsize(stacka))
	{
		while (tmp && tmp->index > -1)
			tmp = tmp->next;
		while (tmp->next && !ft_lstisinf_ind(stacka, (long)(tmp->value)))
		{
			tmp = tmp->next;
			while (tmp && tmp->index > -1)
				tmp = tmp->next;
		}
		tmp->index = ind;
		ind++;
		tmp = *stacka;
	}
}
