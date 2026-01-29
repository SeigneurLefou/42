/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:17:46 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/29 10:21:26 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stacka;
	t_list	*stackb;

	if (argc < 2)
		return (1);
	stacka = ft_parsing(argc, argv);
	if (stacka && (ft_lstsize(&stacka) < 2 || ft_issorted(&stacka)))
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
	stair_sort(&stacka, &stackb);
	ft_lstclear(&stacka, ft_free);
	ft_lstclear(&stackb, ft_free);
	return (0);
}
