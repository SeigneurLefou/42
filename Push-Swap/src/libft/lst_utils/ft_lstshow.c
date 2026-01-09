/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstshow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:21:06 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/08 18:24:33 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ft_lstshow(t_list	**stack)
{
	t_list	*tmp;

	tmp = *stack;

	while (tmp)
	{
		ft_putstr_fd("val:",1);
		ft_putnbr_fd(tmp->value,1);
		ft_putstr_fd(", ",1);
		ft_putnbr_fd(tmp->index,1);
		ft_putendl_fd("",1);
		tmp = tmp->next;
	}
}
