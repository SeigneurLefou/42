/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:41:23 by lchamard          #+#    #+#             */
/*   Updated: 2025/10/28 09:33:29 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	ft_inset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_inset(*s1, set) == 1)
		s1++;
	if (*s1 == '\0')
	{
		trim = ft_calloc(1, sizeof(char));
		return (trim);
	}
	end = ft_strlen(s1);
	while (ft_inset(s1[end - 1], set) == 1)
		end--;
	if (end < 1)
		return ("\0");
	trim = ft_substr(s1, 0, end);
	if (!trim)
		return (NULL);
	return (trim);
}
