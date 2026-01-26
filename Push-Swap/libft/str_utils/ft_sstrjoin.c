/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:20:14 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/26 16:41:47 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_sstrjoin(int argc, char **argv)
{
	char	*res;
	int		i;

	res = NULL;
	i = 1;
	while (i < argc)
	{
		res = ft_strjoin(res, " ");
		res = ft_strjoin(res, argv[i]);
		i++;
	}
	return (res);
}
