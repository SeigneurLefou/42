/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:10:40 by lchamard          #+#    #+#             */
/*   Updated: 2025/12/16 17:39:39 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*tmp1;
	const unsigned char	*tmp2;

	if (!dest && !src)
		return (NULL);
	i = 0;
	tmp1 = dest;
	tmp2 = src;
	while (i < n)
	{
		tmp1[i] = tmp2[i];
		i++;
	}
	return (dest);
}
