/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:54:42 by lchamard          #+#    #+#             */
/*   Updated: 2025/10/17 13:15:24 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;

	dest_len = 0;
	src_len = 0;
	while (dest_len < size && dest[dest_len])
		dest_len++;
	while ((src_len + dest_len + 1) < size && src[src_len])
	{
		dest[dest_len + src_len] = src[src_len];
		src_len++;
	}
	if (dest_len < size)
		dest[dest_len + src_len] = '\0';
	src_len = ft_strlen(src);
	return (dest_len + src_len);
}
