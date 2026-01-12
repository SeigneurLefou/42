/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:17:46 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/12 10:36:29 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

/*
static void	print_stack(t_list **stacka, t_list **stackb)
{
	ft_putendl_fd("A\n_", 1);
	ft_lstshow(stacka);
	ft_putendl_fd("\nB\n_", 1);
	ft_lstshow(stackb);
}
*/

int main(int argc, char **argv)
{
	t_list	*stacka;
	t_list	*stackb;

	(void)stackb;
	if (argc < 2)
	{
		return (1);
	}
	stacka = ft_parsing(argc, argv);
	stackb = NULL;
	if (!stacka)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	stair_sort(&stacka, &stackb);
	ft_lstshow(&stacka);
	return (0);
}
