/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:16:35 by lchamard          #+#    #+#             */
/*   Updated: 2025/10/17 17:28:24 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	*ft_strrchr(char *s, int c)
{
	size_t	i;
	size_t	slen;

	i = ft_strlen(s) - 1;
	slen = ft_strlen(s);
	while (*s)
		s++;
	if (*s == (char)c)
		return (s);
	s--;
	while (*s != (char)c && i-- < slen)
		s--;
	if (*s == (char)c)
		return (s);
	return (NULL);
}
