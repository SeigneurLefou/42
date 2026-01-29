/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:09:03 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/29 16:29:35 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
		return (2);
	}
	input_command = ft_split(input_command_raw, '\n');
	free(input_command_raw);
	if (!is_cmds_exist(stacka, stackb, input_command))
		return (0);
	return (1);
}

void	is_checked(t_list *stacka, t_list *stackb)
{
	int	result;

	result = verif_sort(&stacka, &stackb);
	if (!result)
		ft_putstr_fd("Error\n", 2);
	else if (ft_issorted(&stacka) && ft_lstsize(&stackb) == 0 && result == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&stacka, ft_free);
	ft_lstclear(&stackb, ft_free);
}

int	main(int argc, char **argv)
{
	t_list	*stacka;
	t_list	*stackb;

	if (argc < 2)
		return (0);
	stacka = ft_parsing(argc, argv);
	stackb = NULL;
	if (stacka && ft_lstsize(&stacka) < 2)
	{
		ft_lstclear(&stacka, ft_free);
		return (0);
	}
	if (!stacka)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	is_checked(stacka, stackb);
	stackb = NULL;
	return (0);
}
