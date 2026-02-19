/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:52:54 by lchamard          #+#    #+#             */
/*   Updated: 2025/10/22 15:00:34 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	ft_putendl_fd(char *str, int fd)
{
	int	len;

	if (!str || !fd)
		return (0);
	len = ft_putstr_fd(str, fd);
	len += ft_putchar_fd('\n', fd);
	return (len);
}
