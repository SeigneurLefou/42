/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:20:59 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/13 14:59:49 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdouble(long *numbers)
{
	int	start;
	int	i;

	start = 0;
	i = 1;
	while (numbers[start])
	{
		while (numbers[i])
		{
			if (numbers[i] == numbers[start])
				return (1);
			i++;
		}
		start++;
		i = start + 1;
	}
	return (0);
}
