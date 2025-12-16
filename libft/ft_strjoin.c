/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:18:54 by lchamard          #+#    #+#             */
/*   Updated: 2025/10/28 15:37:00 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*to_fill(char *filler, const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		filler[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		filler[i] = s2[j];
		i++;
		j++;
	}
	return (filler);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len;
	char	*joinstr;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1);
	len += ft_strlen(s2);
	joinstr = ft_calloc(len + 1, sizeof(char));
	if (!joinstr)
		return (NULL);
	to_fill(joinstr, s1, s2);
	return (joinstr);
}
