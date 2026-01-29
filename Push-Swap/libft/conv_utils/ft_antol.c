/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_antol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:22:16 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/29 10:39:46 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sign(char *args, size_t *i)
{
	int	sign;

	sign = 1;
	while (args[*i] == ' ' || (9 <= args[*i] && args[*i] <= 13))
		(*i)++;
	if (args[*i] == '-' || args[*i] == '+')
	{
		if (args[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return (sign);
}

long	ft_antol(char *args, size_t *i)
{
	long	res;
	int		sign;
	int		len;

	res = 0;
	sign = ft_sign(args, i);
	len = 0;
	while (args[*i] == '0')
		(*i)++;
	while ('0' <= args[*i] && args[*i] <= '9')
	{
		res = res * 10 + (args[*i] - '0');
		(*i)++;
		len++;
	}
	if (len > 10)
		return (999999999999);
	return (sign * res);
}
