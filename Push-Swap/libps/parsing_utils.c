/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:52:44 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/29 10:31:59 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_verif_parsing(t_list *tmp, t_list **result, size_t j)
{
	if (!tmp)
		return (0);
	if (INT_MIN > (long)tmp->value || (long)tmp->value > INT_MAX)
	{
		if (j > 0)
			ft_lstadd_back(result, &tmp);
		else
		{
			*result = ft_lstnew((long)tmp->value);
			free(tmp);
		}
		return (0);
	}
	if (j > 0)
		ft_lstadd_back(result, &tmp);
	else
	{
		*result = ft_lstnew((long)tmp->value);
		free(tmp);
	}
	return (1);
}

t_list	*ft_split_int(char *args)
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
		if (!ft_verif_parsing(tmp, &result, j))
		{
			if (result)
				ft_lstclear(&result, ft_free);
			return (NULL);
		}
		j++;
	}
	if (ft_lstisdouble(&result))
	{
		ft_lstclear(&result, ft_free);
		return (NULL);
	}
	return (result);
}

int	ft_count_int(char *args, char *validity_str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (args[i])
	{
		while (args[i] == ' ')
			i++;
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

char	*ft_fuse_argv(char **argv)
{
	int		i;

	i = 0;
	while (argv[i + 1])
	{
		argv[i][ft_strlen(argv[i])] = ' ';
		i++;
	}
	return (argv[0]);
}
