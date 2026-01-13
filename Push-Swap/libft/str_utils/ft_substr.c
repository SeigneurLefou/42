/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:44:00 by lchamard          #+#    #+#             */
/*   Updated: 2025/10/28 15:10:05 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	max;
	char	*sub;

	if (!s)
		return (NULL);
	max = ft_strlen(s);
	if (start > max)
	{
		sub = ft_calloc(1, sizeof(char));
		return (sub);
	}
	if (len > (max - start))
		len = max - start;
	len++;
	sub = ft_calloc(len, sizeof(char));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len);
	return (sub);
}
