/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:44:46 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/05 15:10:59 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static long	*ft_split_int(int nbel, char *args)
{
	long	*result;
	int	i;
	int	j;

	result = ft_calloc(nbel, sizeof(int));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (args[i])
	{
		result[j] = ft_antol(args, &i);
		if (-2147483648 > result[j] || result[j] > 2147483647)
		{
			free(result);
			return (NULL);
		}
		j++;
	}
	if (ft_isdouble(result))
		return (NULL);
	return (result);
}

static int ft_count_int(char *args, char *validity_str)
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

long	*ft_parsing(int argc, char **argv)
{
	int		len;
	long	*result;
	char	*args;
	char	*validity_str;

	len = 0;
	result = NULL;
	validity_str = "-+ \t0123456789";
	if (!argc || !argv)
		return (NULL);
	if (ft_invalid_input(argc, argv, validity_str))
		return (NULL);
	args = ft_sstrjoin(argc, argv);
	if (!args)
		return (NULL);
	len = ft_count_int(args, validity_str);
	if (!len)
		return (NULL);
	result = ft_split_int(len, args);
	if (!result)
		return (NULL);
	return (result);
}
