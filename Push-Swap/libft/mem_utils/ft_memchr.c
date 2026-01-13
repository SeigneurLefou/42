/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:56:15 by lchamard          #+#    #+#             */
/*   Updated: 2025/10/17 17:39:51 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	size_t	i;
	char	*res;

	i = 0;
	res = s;
	while (i < n)
	{
		if (res[i] == (char)c)
			return (&res[i]);
		i++;
	}
	return (NULL);
}
