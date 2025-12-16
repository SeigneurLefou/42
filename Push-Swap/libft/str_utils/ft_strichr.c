/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:20:29 by lchamard          #+#    #+#             */
/*   Updated: 2025/12/16 11:20:43 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strichr(char c, char *str, size_t start)
{
	size_t i;

	if (start >= ft_strlen(str))
		return (0);
	i = start;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);

}
