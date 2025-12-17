/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:44:46 by lchamard          #+#    #+#             */
/*   Updated: 2025/12/17 18:32:11 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	*ft_split_int(int nbel, char *args)
{
	int	*result;
	int	i;
	int	j;

	result = ft_calloc(nbel + 1, sizeof(int));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (args[i])
		result[j++] = ft_antoi(args, &i);
	if (ft_isdouble(result))
		return (NULL);
	return (result);
}

static int ft_count_int(char *args)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (args[i])
	{
		if (!ft_isvalid_start(args, &i))
			return (0);
		len++;
	}
	return (len);
}

int	ft_invalid_input(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isvalid(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int	*ft_parsing(int argc, char **argv)
{
	int		len;
	int		*result;
	char	*args;

	len = 0;
	result = NULL;
	if (!argc || !argv)
		return (NULL);
	if (ft_invalid_input(argc, argv))
		return (NULL);
	args = ft_sstrjoin(argc, argv);
	if (!args)
		return (NULL);
	len = ft_count_int(args);
	result = ft_split_int(len, args);
	if (!result)
		return (NULL);
	return (result);
}
