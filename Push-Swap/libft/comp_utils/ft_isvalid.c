/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:21:10 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/28 11:14:41 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isvalid(const char *numbers, char *validity_str)
{
	int		i;

	i = 0;
	while (numbers[i] == ' ' || numbers[i] == '\t')
		i++;
	if (numbers[i] && !ft_strchr(validity_str, numbers[i]))
		return (0);
	if (numbers[i] == '+' || numbers[i] == '-')
	{
		if (!ft_strchr(validity_str + 4, numbers[++i]))
			return (0);
	}
	else if (!ft_strchr(validity_str + 4, numbers[i++]))
		return (0);
	while (ft_strchr(validity_str + 4, numbers[i]))
		i++;
	if (numbers[i] && !ft_strchr(validity_str + 2, numbers[i]))
		return (0);
	return (1);
}

int	ft_isvalid_start(const char *numbers, int	*start, char *validity_str)
{
	int		i;

	i = *start;
	while (numbers[i] == ' ' || numbers[i] == '\t')
		i++;
	if (!numbers[i])
		return (1);
	if (numbers[i] && !ft_strchr(validity_str, numbers[i]))
		return (0);
	if (numbers[i] == '+' || numbers[i] == '-')
	{
		if (!ft_strchr(validity_str + 4, numbers[++i]))
			return (0);
	}
	else if (!ft_strchr(validity_str + 4, numbers[i++]))
		return (0);
	while (ft_strchr(validity_str + 4, numbers[i]))
		i++;
	if (numbers[i] && !ft_strchr(validity_str + 2, numbers[i]))
		return (0);
	*start = i;
	return (1);
}
