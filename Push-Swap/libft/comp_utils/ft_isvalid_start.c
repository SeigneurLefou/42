/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:21:10 by lchamard          #+#    #+#             */
/*   Updated: 2025/12/18 20:27:17 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isvalid_start(const char *numbers, int	*start, char *validity_str)
{
	int		i;

	i = *start;
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
	while (numbers[i] && ft_strchr(validity_str + 4, numbers[i]))
		i++;
	if (numbers[i] && !ft_strchr(validity_str + 2, numbers[i]))
		return (0);
	*start = i;
	return (1);
}
