/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:24:51 by lchamard          #+#    #+#             */
/*   Updated: 2025/10/28 16:07:39 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	ft_count(int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		count++;
		nb *= -1;
	}
	while (nb)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

static char	*ft_alloc(long int nb)
{
	char	*res;

	res = ft_calloc(ft_count(nb) + 1, sizeof (char));
	if (!res)
	{
		return (NULL);
	}
	return (res);
}

static char	*ft_fill(char *res, long int nb_overlap, int len)
{
	size_t	i;

	i = 0;
	if (nb_overlap < 0)
	{
		res[i] = '-';
		len++;
		i = 1;
		nb_overlap *= -1;
	}
	while (nb_overlap)
	{
		res[len - i++] = (nb_overlap % 10) + '0';
		nb_overlap /= 10;
	}
	return (res);
}

char	*ft_itoa(int nb)
{
	char		*res;
	int			len;
	long int	nb_overlap;

	if (nb == 0)
	{
		res = ft_calloc(2, sizeof(char));
		if (!res)
			return (NULL);
		res[0] = '0';
		return (res);
	}
	nb_overlap = nb;
	res = ft_alloc(nb_overlap);
	if (!res)
		return (NULL);
	len = ft_count(nb) - 1;
	ft_fill(res, nb_overlap, len);
	return (res);
}
