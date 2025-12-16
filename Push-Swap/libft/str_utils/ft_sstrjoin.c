/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:20:14 by lchamard          #+#    #+#             */
/*   Updated: 2025/12/16 18:01:42 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_sstrjoin(int argc, char **argv)
{
	char	*res;
	int		i;

	res = NULL;
	i = 1;
	while (i < argc)
	{
		ft_strjoin(res, argv[i]);
		i++;
	}
	ft_strjoin(res, "\0");
	return (res);
}
