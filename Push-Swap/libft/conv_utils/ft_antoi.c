/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_antoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:22:16 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/13 14:59:08 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_antoi(char *args, size_t *i)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (args[*i] == ' ' || (9 <= args[*i] && args[*i] <= 13))
		(*i)++;
	if (args[*i] == '-' || args[*i] == '+')
	{
		if (args[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	while ('0' <= args[*i] && args[*i] <= '9')
	{
		res = res * 10 + (args[*i] - '0');
		(*i)++;
	}
	return (sign * res);
}
