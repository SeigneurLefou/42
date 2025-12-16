/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:38:30 by lchamard          #+#    #+#             */
/*   Updated: 2025/11/19 11:49:48 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return (1);
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (nmemb > ((size_t) -1) / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (i < (nmemb * size))
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

char	*ft_strnjoin(char *s1, char *s2, size_t size)
{
	char	*joinstr;
	size_t	i;
	size_t	j;

	joinstr = ft_calloc(size + 1, sizeof(char));
	if (!joinstr)
		return (NULL);
	i = 0;
	while (s1 && s1[i] && i < size)
	{
		joinstr[i] = s1[i];
		i++;
	}
	free(s1);
	j = 0;
	while (s2 && s2[j] && i < size)
	{
		joinstr[i] = s2[j];
		i++;
		j++;
	}
	return (joinstr);
}
