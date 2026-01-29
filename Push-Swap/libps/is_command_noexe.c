/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_command_noexe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:13:45 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/29 16:14:00 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_swap_noexe(char *cmd)
{
	if (!(ft_strncmp("sa", cmd, 2) == 0) && !(ft_strncmp("sb", cmd, 2) == 0)
		&& !(ft_strncmp("ss", cmd, 2) == 0))
		return (0);
	return (1);
}

int	is_reverse_rotate_noexe(char *cmd)
{
	if (!(ft_strncmp("rra", cmd, 3) == 0) && !(ft_strncmp("rrb", cmd, 3) == 0)
		&& !(ft_strncmp("rrr", cmd, 3) == 0))
		return (0);
	return (1);
}

int	is_rotate_noexe(char *cmd)
{
	if (!(ft_strncmp("ra", cmd, 2) == 0) && !(ft_strncmp("rb", cmd, 2) == 0)
		&& !(ft_strncmp("rr", cmd, 2) == 0))
		return (0);
	return (1);
}

int	is_push_noexe(char *cmd)
{
	if (!(ft_strncmp("pa", cmd, 2) == 0) && !(ft_strncmp("pb", cmd, 2) == 0))
		return (0);
	return (1);
}
