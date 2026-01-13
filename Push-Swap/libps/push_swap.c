/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:44:46 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/13 16:13:55 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_split_int(char *args)
{
	t_list	*result;
	t_list	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (args[i])
	{
		tmp = ft_lstnew(ft_antol(args, &i));
		if (INT_MIN > tmp->value || tmp->value > INT_MAX)
			return (NULL);
		if (j > 0)
			ft_lstadd_back(&result, &tmp);
		else
			result = ft_lstnew(tmp->value);
		j++;
	}
	if (ft_lstisdouble(&result))
		return (NULL);
	return (result);
}

static int	ft_count_int(char *args, char *validity_str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (args[i])
	{
		if (!ft_isvalid_start(args, &i, validity_str))
			return (0);
		len++;
	}
	return (len);
}

int	ft_invalid_input(int argc, char **argv, char *validity_str)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isvalid(argv[i], validity_str))
			return (1);
		i++;
	}
	return (0);
}

t_list	*ft_parsing(int argc, char **argv)
{
	char	*args;
	char	*validity_str;
	t_list	*result;

	validity_str = "-+ \t0123456789";
	if (!argc || !argv)
		return (NULL);
	if (ft_invalid_input(argc, argv, validity_str))
		return (NULL);
	args = ft_sstrjoin(argc, argv);
	if (!args)
		return (NULL);
	if (!ft_count_int(args, validity_str))
		return (NULL);
	result = ft_split_int(args);
	if (!(result))
		return (NULL);
	return (result);
}
