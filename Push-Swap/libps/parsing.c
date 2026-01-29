/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:44:46 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/29 10:21:55 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_parsing(int argc, char **argv)
{
	char	*validity_str;
	char	*args;
	t_list	*result;

	validity_str = "-+ \t0123456789";
	if (!argc || !argv)
		return (NULL);
	if (ft_invalid_input(argc, argv, validity_str))
		return (NULL);
	args = ft_fuse_argv(argv + 1);
	if (!ft_count_int(args, validity_str))
		return (NULL);
	result = ft_split_int(args);
	if (!(result))
		return (NULL);
	return (result);
}
