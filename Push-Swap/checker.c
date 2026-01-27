/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:09:03 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/27 17:44:55 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "stdio.h"

void	ft_free_double_list(char **dlist)
{
	int	i;

	i = 0;
	while (dlist[i])
		free(dlist[i++]);
	free(dlist);
}

int	is_cmds_exist(t_list **stacka, t_list **stackb, char **input_command)
{
	int		i;

	i = 0;
	while (input_command[i])
	{
		if (!is_swap(input_command[i], stacka, stackb)
			&& !is_push(input_command[i], stacka, stackb)
			&& !is_reverse_rotate(input_command[i], stacka, stackb)
			&& !is_rotate(input_command[i], stacka, stackb))
		{
			ft_free_double_list(input_command);
			return (0);
		}
		i++;
	}
	ft_free_double_list(input_command);
	return (1);
}

int	verif_sort(t_list **stacka, t_list **stackb)
{
	char	*input_command_raw;
	char	**input_command;

	input_command_raw = get_file();
	if (!input_command_raw)
	{
		if (ft_issorted(stacka))
			return (1);
		return (0);
	}
	input_command = ft_split(input_command_raw, '\n');
	free(input_command_raw);
	if (!is_cmds_exist(stacka, stackb, input_command))
		return (0);
	if (ft_issorted(stacka))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stacka;
	t_list	*stackb;

	if (argc < 2)
		return (1);
	stacka = ft_parsing(argc, argv);
	if (stacka && ft_lstsize(&stacka) < 2)
	{
		ft_lstclear(&stacka, ft_free);
		return (1);
	}
	if (!stacka)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	stackb = NULL;
	if (verif_sort(&stacka, &stackb))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&stacka, ft_free);
	ft_lstclear(&stackb, ft_free);
	return (0);
}
