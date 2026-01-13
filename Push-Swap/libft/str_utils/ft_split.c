/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 09:58:02 by lchamard          #+#    #+#             */
/*   Updated: 2025/10/28 17:09:01 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	ft_count(char const *s, char c)
{
	size_t	i;
	int		count;

	i = 1;
	count = 0;
	if (s[0] != '\0' && s[0] != c)
		count++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static void	ft_free_all(char **tofree)
{
	int	i;

	i = 0;
	while (tofree[i])
	{
		free(tofree[i]);
		i++;
	}
	free(tofree);
}

static char	*ft_extract_word(char const *s, char c)
{
	int		wlen;
	char	*word;

	wlen = 0;
	while (s[wlen] && s[wlen] != c)
		wlen++;
	word = ft_calloc(wlen + 1, sizeof(char));
	if (!word)
		return (NULL);
	ft_memcpy(word, s, wlen);
	return (word);
}

static char	**ft_real_split(char **tofill, char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			tofill[i] = ft_extract_word(s, c);
			if (!tofill[i])
			{
				ft_free_all(tofill);
				return (NULL);
			}
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	tofill[i] = NULL;
	return (tofill);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = ft_calloc(ft_count(s, c) + 1, sizeof(char *));
	if (!res)
		return (NULL);
	res = ft_real_split(res, s, c);
	return (res);
}
