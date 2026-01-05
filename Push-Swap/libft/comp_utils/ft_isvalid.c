/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:21:10 by lchamard          #+#    #+#             */
/*   Updated: 2025/12/18 19:46:45 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isvalid(const char *numbers, char *validity_str)
{
	int		i;

	i = 0;
	while (numbers[i] == ' ' || numbers[i] == '\t') 
		i++;
	if (!ft_strchr(validity_str, numbers[i]))
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
	return (1);
}
