/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:21:10 by lchamard          #+#    #+#             */
/*   Updated: 2025/12/16 11:35:49 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isvalid(const char *numbers, int	start)
{
	size_t	i;
	char	*valid_c;

	i = start;
	valid_c = " \t+-0123456789";
	while (numbers[i] == ' ' || numbers[i] == '\t') 
	{
		if (!ft_strchr(valid_c, numbers[i]))
			return (0);
		i++;
	}
	if (numbers[i] == '+' || numbers[i] == '-') 
		if (!ft_strchr(valid_c + 4, numbers[++i]))
			return (0);
	if (!ft_strchr(valid_c + 4, numbers[++i]))
		return (0);
	while (ft_strchr(valid_c + 4, numbers[++i]))
		i++;
	return (1);
}
