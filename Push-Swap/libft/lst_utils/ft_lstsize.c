/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:06:18 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/13 15:06:19 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list **lst)
{
	size_t	len;
	t_list	*tmp;

	len = 1;
	if (!lst)
		return (0);
	tmp = *lst;
	if (!tmp)
		return (0);
	while (tmp->next)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}
