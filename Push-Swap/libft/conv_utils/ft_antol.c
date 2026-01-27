/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_antol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:22:16 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/27 14:44:16 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_antol(char *args, size_t *i)
{
	long	res;
	int		sign;
	int		len;

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
	len = 0;
	while ('0' <= args[*i] && args[*i] <= '9')
	{
		res = res * 10 + (args[*i] - '0');
		(*i)++;
		len++;
	}
	if (len > 10)
		return (LONG_MAX);
	return (sign * res);
}
