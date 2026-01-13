/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:16:43 by lchamard          #+#    #+#             */
/*   Updated: 2025/12/16 17:39:23 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*destcpy;
	const unsigned char	*srccpy;

	if (!dest && !src)
		return (NULL);
	destcpy = dest;
	srccpy = src;
	if (src < dest)
	{
		i = n - 1;
		while (i < n)
		{
			destcpy[i] = srccpy[i];
			i--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
