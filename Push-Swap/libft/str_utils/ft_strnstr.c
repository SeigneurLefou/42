/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:36:17 by lchamard          #+#    #+#             */
/*   Updated: 2025/10/29 14:53:08 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	to_find_len;
	char	*str;
	char	*to_find;

	to_find_len = ft_strlen(little);
	i = 0;
	str = (char *) big;
	to_find = (char *) little;
	if (to_find_len == 0)
		return (str);
	while (str[i] && i < len)
	{
		if (ft_strncmp(&str[i], to_find, to_find_len) == 0
			&& i + to_find_len <= len)
		{
			return (&str[i]);
		}
		i++;
	}
	return (NULL);
}
