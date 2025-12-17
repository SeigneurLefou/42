/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:21:10 by lchamard          #+#    #+#             */
/*   Updated: 2025/12/17 11:30:46 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isvalid(const char *numbers, int	*start)
{
	int		i;
	char	*valid_c;

	i = *start;
	valid_c = " \t+-0123456789";
	while (numbers[i] == ' ' || numbers[i] == '\t') 
		i++;
	if (!ft_strchr(valid_c, numbers[i]))
		return (0);
	if (numbers[i] == '+' || numbers[i] == '-') 
	{
		if (!ft_strchr(valid_c + 4, numbers[++i]))
			return (0);
	}
	else if (!ft_strchr(valid_c + 4, numbers[++i]))
		return (0);
	while (ft_strchr(valid_c + 4, numbers[++i]))
		i++;
	*start = i;
	return (1);
}
