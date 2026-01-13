/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:17:46 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/13 14:45:13 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
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
	return (0);
}
