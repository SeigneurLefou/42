/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:13:45 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/27 17:26:15 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_swap(char *cmd, t_list **stacka, t_list **stackb)
{
	if (ft_strncmp("sa", cmd, 2) == 0)
		ft_swap(stacka);
	else if (ft_strncmp("sb", cmd, 2) == 0)
		ft_swap(stackb);
	else if (ft_strncmp("ss", cmd, 2) == 0)
	{
		ft_swap(stacka);
		ft_swap(stackb);
	}
	else
		return (0);
	return (1);
}

int	is_reverse_rotate(char *cmd, t_list **stacka, t_list **stackb)
{
	if (ft_strncmp("rra", cmd, 3) == 0)
		ft_reverse_rotate(stacka);
	else if (ft_strncmp("rrb", cmd, 3) == 0)
		ft_reverse_rotate(stackb);
	else if (ft_strncmp("rrr", cmd, 3) == 0)
	{
		ft_reverse_rotate(stacka);
		ft_reverse_rotate(stackb);
	}
	else
		return (0);
	return (1);
}

int	is_rotate(char *cmd, t_list **stacka, t_list **stackb)
{
	if (ft_strncmp("ra", cmd, 2) == 0)
		ft_rotate(stacka);
	else if (ft_strncmp("rb", cmd, 2) == 0)
		ft_rotate(stackb);
	else if (ft_strncmp("rr", cmd, 2) == 0)
	{
		ft_rotate(stacka);
		ft_rotate(stackb);
	}
	else
		return (0);
	return (1);
}

int	is_push(char *cmd, t_list **stacka, t_list **stackb)
{
	if (ft_strncmp("pa", cmd, 2) == 0)
		ft_push(stackb, stacka);
	else if (ft_strncmp("pb", cmd, 2) == 0)
		ft_push(stacka, stackb);
	else
		return (0);
	return (1);
}
