/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:44:46 by lchamard          #+#    #+#             */
/*   Updated: 2025/12/16 17:56:39 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	*ft_parsing(int argc, char **argv)
{
	int		i;
	int		j;
	int		*result;
	char	*args;

	i = 1;
	j = 0;
	if (!argc || !argv)
		return (NULL);
	result = malloc((argc - 1) * sizeof(int));
	args = ft_sstrjoin(argc, argv);
	if (!result)
		return (NULL);
	while (args[i])
	{
		if (!ft_isvalid(args, i))
		{
			free(result);
			return (NULL);
		}
		result[j] = ft_antoi(args, &i);
		j++;
	}
	if (ft_isdouble(result))
		return (NULL);
	return (result);
}
