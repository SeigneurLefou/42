/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:06:07 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/26 18:58:14 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(long content)
{
	t_list	*new_list;

	new_list = ft_calloc(1, sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->value = (void *)content;
	new_list->index = -1;
	return (new_list);
}
