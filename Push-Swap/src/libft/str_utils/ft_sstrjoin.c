/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:20:14 by lchamard          #+#    #+#             */
/*   Updated: 2025/12/17 11:14:07 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

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
