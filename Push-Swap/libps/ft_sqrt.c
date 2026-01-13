/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:17:32 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/13 15:17:50 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int nb)
{
	int	sqrt_nb;

	if (nb == 1)
		return (1);
	sqrt_nb = 1;
	while ((sqrt_nb * sqrt_nb) < nb)
	{
		if (sqrt_nb * sqrt_nb == nb)
			return (sqrt_nb);
		sqrt_nb++;
	}
	return (sqrt_nb);
}
