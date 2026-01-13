/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:04:01 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/13 15:04:02 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstiter(t_list **lst, void (*f)(long))
{
	t_list	*tmp;

	if (!(*lst) || !f)
		return ;
	tmp = *lst;
	while (tmp)
	{
		f(tmp->value);
		tmp = tmp->next;
	}
}
